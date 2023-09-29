/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:14:52 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/29 17:04:44 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(char *msg, int exit_code)
{
	perror(msg);
	exit(exit_code);
}

void 	pipex(char *argv, char **envp)
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
		execute(argv, envp);
	}
	else
	{
		close(pipe_fd[1]);
		waitpid(pid, NULL, 0);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
	}
}

int 	main(int argc, char **argv, char **envp) 
{
	int i;
	
	i = 0;
	if (argc < 5)
	{
		ft_printf("pipex: usage:\n./pipex infile cmd1 cmd2 cmd3 ... cmdn outfile\n");
		ft_printf("./pipex here_doc LIMITER cmd1 cmd2 cmd3 ... cmdn outfile\n");
		exit(ERROR);
	}
	else if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		create_here_doc(argv);
		unlink("here_doc");
		i = 3;
	}
	else
		process_file(argv[1], IN_FILE);
	while (i < argc - 2)
		pipex(argv[i++], envp);
	process_file(argv[argc - 1], OUT_FILE);
	execute(argv[argc - 2], envp);
}
