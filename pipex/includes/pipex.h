/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:49:31 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/19 15:42:15 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

// pipex_main.c
int	ft_fork();

// pipex_utils_args.c
char 	**ft_clean_argv(int argc, char **argv);
char	**ft_parse_envp(char **envp);
char	*get_cmd_path(char **clean_envp, char *cmd);

// pipex_utils_checker.c
int		check_args(int argc);
void	ft_error(char *str, int exit_code);
void	free_tab_and_exit(char **strs, char *message);

#endif
