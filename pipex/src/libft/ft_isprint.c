/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:10:57 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/04/19 13:06:34 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks whether a character is printable or not. */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
