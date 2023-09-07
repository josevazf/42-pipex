/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:47:37 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/04/19 14:31:26 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Compares up to size characters of string 's1' to those of string 's2'. */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && (s1[i] == s2[i]) && s1[i] != '\0')
		i++;
	if (i < size)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (0);
}
