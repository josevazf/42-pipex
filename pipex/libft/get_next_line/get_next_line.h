/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:31:27 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/29 18:01:35 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
size_t	ft_strlen2(const char *s);
char	*ft_strchr2(const char *str, int c);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strtrim_l(char *bufftxt);
char	*ft_strtrim_r(char *bufftxt);
char	*ft_get_text(int fd, char *bufftxt);

#endif
