/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:49:31 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/05 10:14:43 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

// check_args.c
int		check_args(char **argv);
int		is_number(char *argv);
int		is_duplicate(char **argv);

// check_args_utils.c
int		is_sign(char c);
int		is_digit(char c);
int		intcmp(const char *s1, const char *s2);
long	ft_atoi(const char *str);
int		is_delimiter(char c);


#endif
