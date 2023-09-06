/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:13:48 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/04/19 14:38:08 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Converts 'c' to its uppercase equivalent if 'c' is a lowercase letter 
   and has a uppercase equivalent. 
   If no such conversion is possible, the value returned is 'c' unchanged. */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
