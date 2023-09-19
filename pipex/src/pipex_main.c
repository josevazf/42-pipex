/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:14:52 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/19 15:42:40 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_fork()
{
	pid_t	pid; // Stores the return value of fork
	
	pid = fork(); // Creating the child process
	if (pid == -1)
		return (1);
	return (0);
}

int main(int argc, char **argv, char **envp) 
{
	char	**cmd;
	char	*cmd_path;
	int 	i;

	i = 0;
	check_args(argc);
	cmd = ft_split(argv[1], ' ');
	cmd_path = get_cmd_path(ft_parse_envp(envp), ft_firstword(argv[1]));
	// create parent
	// create children
	// 
	execve(cmd_path, cmd, envp);
}
