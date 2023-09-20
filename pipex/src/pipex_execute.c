/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:46:06 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/20 11:47:41 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h";

void	ft_execute(char *argv, char **envp) 
{
	char	**cmds;
	char	**cmd;
	char	**paths;
	char	*cmd_path;

	cmd = ft_firstword(argv[1]);
	cmds = ft_split(argv, ' ');
	paths = ft_parse_envp(envp);
	cmd_path = get_cmd_path(paths, cmd);
	if (cmd_path == NULL)
	{
		ft_free_matrix(cmd);
		ft_free_matrix(cmd_path);
	}
	if (execve(cmd_path, cmd, envp) == -1)
		ft_error("Could not execute execve", 1);
}