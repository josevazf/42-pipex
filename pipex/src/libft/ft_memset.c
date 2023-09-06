/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:01:51 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/04/19 14:33:37 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Sets the first 'len' bytes of the block of memory pointed by 'dest' 
   to the specified value 'c'. */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
		((unsigned char *)dest)[i] = (unsigned char) c;
	return (dest);
}
