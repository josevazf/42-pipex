/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:14:52 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/08 16:03:19 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(int *fd_pipe, char **argv, char **clean_envp)
{
	int 	fd_file;
	char	*file;
	
	close(fd_pipe[0]); // Closing pipe Read end 
	file = argv[1];
	
}

int 	main(int argc, char **argv, char **envp) 
{
	char	**clean_envp;
	//char	**cmd;
	//char	*cmd_path;
	int		fd_pipe[2];
	int		pid;
	int 	i;


	i = 0;
	clean_envp = ft_parse_envp(envp);
	if (argc != 5)
	{
		printf("Bad arg usage");
		return (1);
	}
	if (pipe(fd_pipe) == -1)
		return (1);
	pid = fork();
	if (pid == -1);
		return (1);
	if (pid == 0)
		child(fd_pipe, argv, clean_envp);
	wait(NULL);
	parent(fd_pipe, argv, clean_envp);
	return (0);
/* 	cmd = ft_split(argv[1], ' '); // alterar para 1
	cmd_path = get_cmd_path(clean_envp, cmd[0]); */
	


	
/* 	i = 0;
	while (clean_envp[i])
	{
		printf("envp[%d]: %s\n", i, clean_envp[i]);
		i++;
	}
	if (execve(cmd_path, cmd, envp) == -1)
	{
		return (2);
	} */
}