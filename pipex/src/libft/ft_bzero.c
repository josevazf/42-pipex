/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:51:33 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/04/19 13:04:18 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Place len zero-valued bytes in the area pointed to by s. */

#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
}
