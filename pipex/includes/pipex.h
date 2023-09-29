/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:49:31 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/29 18:35:44 by jrocha-v         ###   ########.fr       */
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
# define CMD_NOT_FOUND 127
# define IN_FILE 0
# define OUT_FILE 1

// pipex_main.c
void 	pipex(char **argv, char **envp);
void	ft_error(char *msg, int exit_code);

// pipex_utils.c
char	**parse_path(char **envp);
char	*get_cmd_path(char **clean_envp, char *cmd);

// pipex_execute.c
void 	process_dev_urandom(void);
void	process_file(char *file_name, int file_type);
void	execute(char *argv, char **envp);

#endif
