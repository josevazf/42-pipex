/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:14:52 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/20 14:23:48 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_child(int *pipe_fd, char *argv, char **envp)
{
	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	execute(argv, envp);
}

void 	process_parent(pid_t pid, int *pipe_fd, char *argv, char **envp)
(
	close(pipe_fd[1]);
	waitpid(pid, NULL, 0);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	execute(argv, envp);
)

void 	pipex(int argc, chat **argv, char **envp)
{
	pid_t 	pid;
	int 	pipe_fd[2];
	
	process_file(argv[1], IN_FILE);
	if (pipe(pipe_fd) == -1)
		ft_error("Failed creating pipe.", ERROR);
	pid = fork();
	if (pid == -1)
		ft_error("Failed creating fork.", ERROR);
	if (pid == 0)
		process_child(pid, pipe_fd, argv[2], envp);
	else
	{
		process_file(argv[4], OUT_FILE);
		process_parent(pid, pipe_fd, argv[3], envp);
	}
}

int 	main(int argc, char **argv, char **envp) 
{

	check_args(argc);
	pipex(argc, argv, envp);
	// open file to write to

	
}
