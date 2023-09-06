/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:17:23 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/04/19 14:37:31 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Converts 'c' to its lowercase equivalent if 'c' is an uppercase letter 
   and has a lowercase equivalent. 
   If no such conversion is possible, the value returned is 'c' unchanged. */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
