/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:35:00 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/04/19 14:32:25 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Appends the string 'src' to the end of 'dest'. 
   It will append at most 'size − strlen(dest) − 1' bytes. */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	ldest;
	size_t	lsrc;

	i = 0;
	ldest = ft_strlen(dest);
	lsrc = ft_strlen(src);
	if (size <= ldest)
		return (lsrc + size);
	while (src[i] && ((ldest + i) < (size - 1)))
	{
		dest[ldest + i] = src[i];
		i++;
	}
	dest[ldest + i] = '\0';
	return (ldest + lsrc);
}
