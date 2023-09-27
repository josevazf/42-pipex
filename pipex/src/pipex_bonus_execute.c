/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_execute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:46:06 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/27 12:39:13 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	process_here_doc(char **argv)
{
	int		file_fd;
	char 	*input;
	
	if (open("here_doc", O_RDWR | O_CREAT | O_APPEND, 0644) == -1)
	{
		unlink("here_doc");
		ft_error("pipex: here_doc error", ERROR);
	}
	while(1)
	{
		ft_putstr_fd("here_doc>", 1);
		input = get_next_line(0);
		if (!input)
			ft_error("pipex: input error", 1);
		if (ft_strlen(input) == (ft_strlen(argv[2]) + 1) && \
			ft_strncmp(input, argv[2], ft_strlen(argv[2])) == 0)
		{
			free(input);
			break ;
		}
		ft_putstr_fd(input, file_fd);
		free(input);
	}
}

void	process_file(char *file_name, int file_type)
{
	int	file_fd;

	if (file_type == IN_FILE)
		file_fd = open(file_name, O_RDONLY);
	if (file_type == OUT_FILE)
		file_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644); // owner r/w, group/others r
	if (file_fd == -1)
		ft_error("pipex: file error", ERROR);
	if (file_type == IN_FILE)
		dup2(file_fd, STDIN_FILENO);
	if (file_type == OUT_FILE)
		dup2(file_fd, STDOUT_FILENO);
	close(file_fd);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	**paths;
	char	*cmd_path;

	cmd = ft_split(argv, ' ');
	paths = parse_path(envp);
	cmd_path = get_cmd_path(paths, cmd[0]);
	if (cmd_path == NULL)
	{
		ft_free_matrix(cmd);
		ft_free_matrix(paths);
		free(cmd_path);
		ft_error(ft_strjoin("pipex: ", argv), CMD_NOT_FOUND);
	}
	if (execve(cmd_path, cmd, envp) == -1)
	{
		ft_free_matrix(cmd);
		ft_free_matrix(paths);
		free(cmd_path);
		ft_error(ft_strjoin("pipex: ", argv), CMD_NOT_FOUND);
	}
	ft_free_matrix(cmd);
	ft_free_matrix(paths);
	free(cmd_path);
}

