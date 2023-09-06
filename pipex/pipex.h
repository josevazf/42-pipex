/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:49:31 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/06 10:42:34 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// ft_split.c
int		ft_isdelimiter(char c);
int		ft_countwords(char *str);
char 	*ft_substring(int start, int end, char *str);
char 	**ft_split(char *str);

// utils.c
int		ft_strlen(char *str);
char 	**ft_clean_argv(int argc, char **argv);

#endif
