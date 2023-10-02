/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:49:31 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/10/02 10:17:47 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# define SUCCESS 0
# define ERROR 1
# define CMD_NOT_FOUND 127
# define IN_FILE 0
# define OUT_FILE 1

// pipex_bonus_main.c
void	pipex(char *argv, char **envp);
void	ft_error(char *msg, int exit_code);
int		check_args(int argc);

// pipex_bonus_utils.c
char	**parse_path(char **envp);
char	*get_cmd_path(char **clean_envp, char *cmd);

// pipex_bonus_execute.c
void	process_dev_urandom(void);
void	clean_here_doc(void);
void	process_here_doc(char **argv);
void	process_file(char *file_name, int file_type);
void	execute(char *argv, char **envp);

#endif
