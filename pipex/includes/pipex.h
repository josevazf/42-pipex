/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:49:31 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/21 10:49:38 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
# define SUCCESS 0
# define ERROR 1
# define IN_FILE 0
# define OUT_FILE 1

// pipex_main.c
void 	pipex(char **argv, char **envp);
/* void	process_child(int *pipe_fd);
void 	process_parent(pid_t pid, int *pipe_fd); */

// pipex_utils_args.c
char	**parse_path(char **envp);
char	*get_cmd_path(char **clean_envp, char *cmd);

// pipex_err_checker.c
int		check_args(int argc);
void	ft_error(char *str, int exit_code);
void	free_tab_and_exit(char **strs, char *message);

// pipex_execute.c
void	process_file(char *file_name, int file_type);
void	execute(char *argv, char **envp);

#endif
