/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:46:06 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/20 11:51:29 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h";

void	ft_execute(char *argv, char **envp) 
{
	char	**cmd;
	char	**paths;
	char	*cmd_path;

	cmd = ft_split(argv, ' ');
	paths = ft_parse_envp(envp);
	cmd_path = get_cmd_path(paths, cmd[0]);
	if (cmd_path == NULL)
	{
		ft_free_matrix(cmd);
		ft_free_matrix(paths);
		free(cmd);
		ft_error("Error finding path", 1);
	}
	if (execve(cmd_path, cmd, envp) == -1)
	{		
		ft_free_matrix(cmd);
		ft_free_matrix(paths);
		free(cmd);
		ft_error("Could not execute command", 1);
	}
}
