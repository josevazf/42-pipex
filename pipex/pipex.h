/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:49:31 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/06 19:40:09 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// utils_libft.c
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
int		ft_countwords(char *s, char c);
char	*ft_strposi(char *s, char c, int pos);
char	**ft_split(char *s, char c);
int		ft_strncmp(char *s1, char *s2, size_t size);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);

// utils_argv.c
char 	**ft_clean_argv(int argc, char **argv);
char	**ft_parse_envp(char **envp);

#endif
