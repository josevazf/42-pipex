/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:53:20 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/04/19 14:34:31 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Searches for the first occurrence of the character 'c'
   in the first 'len' bytes of the string pointed to, by the argument 's'. */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t				i;
	unsigned char const	*str;

	str = (unsigned char const *)s;
	i = 0;
	while (i < len)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (0);
}
