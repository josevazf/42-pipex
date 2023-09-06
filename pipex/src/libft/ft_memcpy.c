/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:33:11 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/04/19 14:34:01 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copies the values of 'len' bytes from the location pointed to by 'src' 
   directly to the memory block pointed to by 'dest'. */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (!dest && !src)
		return (NULL);
	while (++i < len)
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	return (dest);
}
