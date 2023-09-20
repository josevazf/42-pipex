/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:14:52 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/20 11:14:54 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void pipex(int argc, chat **argv, char **envp)
{
	pid_t pid;
	int pipe_fd[2];
	
	if (pipe(pipe_fd) == -1)
		ft_error("Failed creating pipe!", 1);
	pid = fork();
	if (pid == -1)
		ft_error("Failed creating fork!", 2);
	if (pid == 0)
	[
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
	]
	
}


int main(int argc, char **argv, char **envp) 
{

	
	check_args(argc);
	// open file to read
	open_file(argv[1], IN_FILE);
	// create pipe
	pipex(argc, argv, envp);
	
	// execute first command
	ft_execute(argv[1], argv[1], envp);
	// redirect to pipe 
	// open file to write to
	open_file(argv[4], OUT_FILE);
	
}
