/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:14:52 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/29 18:25:53 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *msg, int exit_code)
{
	perror(msg);
	exit(exit_code);
}

void 	pipex(char **argv, char **envp)
{
	pid_t 	pid;
	int 	pipe_fd[2];
	
	if (pipe(pipe_fd) == -1)
		ft_error("pipex: failed creating pipe", ERROR);
	pid = fork();
	if (pid == -1)
		ft_error("pipex: failed creating fork", ERROR);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		execute(argv[2], envp);
	}
	else
	{
		close(pipe_fd[1]);
		waitpid(pid, NULL, 0);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		process_file(argv[4], OUT_FILE);
		execute(argv[3], envp);
	}
}

int 	main(int argc, char **argv, char **envp) 
{
	if (argc != 5)
	{
		ft_printf("pipex: usage:\n./pipex infile cmd1 cmd2 outfile\n");
		exit(ERROR);
	}
	else if (ft_strncmp(argv[1], "/dev/urandom", ft_strlen("/dev/urandom")) == 0)
	{
		process_dev_urandom();
		unlink("temp_urandom");
	}
	else
		process_file(argv[1], IN_FILE);
	pipex(argv, envp);
}
