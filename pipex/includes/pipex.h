/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:49:31 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/07 13:06:37 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// utils_argv.c
char	**ft_parse_envp(char **envp); 					// OK
char	*get_first_word(char *argv); 					// OK
char	*get_cmd_path(char **clean_envp, char *cmd);

// utils_lib.c (add to libft)
int		ft_isdelimiter(char s, char c); 				// OK
int		ft_iswhitespace(char c); 						// OK

// FREEEEE
// free(paths) from ft_parse_envp

#endif
