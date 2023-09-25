/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:46:06 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/25 16:20:08 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Find 'PATH=' in envp file and return the paths delimited by ':'
char	**parse_path(char **envp)
{
	char 	*envp_dup;
	char	**paths;
	int 	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break;
		i++;
	}
	if (envp[i] == NULL)
		return (NULL);
	envp_dup = ft_strdup(envp[i] + 5);
	if (envp_dup == NULL)
		return (NULL);
	paths = ft_split(envp_dup, ':');
	free(envp_dup);
	if (paths == NULL)
		return (NULL);
	return (paths);	
}

// Get the full path for the command to execute
char	*get_cmd_path(char **envp_paths, char *cmd)
{
	char	*temp_path;
	char	*new_path;
	int 	i;
	
	i = 0;
	while(envp_paths[i])
	{
		temp_path = ft_strjoin(envp_paths[i], "/");
		if (temp_path == NULL)
			return (NULL);
		new_path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (new_path == NULL)
			return (NULL);
		if (access(new_path, X_OK) == 0)
			return (new_path);
		free(new_path);
		i++;		
	}
	return (NULL);
}

void	process_file(char *file_name, int file_type)
{
	int	file_fd;

	if (file_type == IN_FILE)
		file_fd = open(file_name, O_RDONLY);
	if (file_type == OUT_FILE)
		file_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644); // owner r/w, group/others r
	if (file_fd == -1)
		ft_error("Infile error", ERROR);
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
		ft_error("Error finding path", ERROR);
	}
	if (execve(cmd_path, cmd, envp) == -1)
	{
		ft_free_matrix(cmd);
		ft_free_matrix(paths);
		free(cmd_path);
		ft_error("Error executing command", ERROR);
	}
}
