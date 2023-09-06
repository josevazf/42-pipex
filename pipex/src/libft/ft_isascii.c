/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:01:39 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/04/19 13:06:19 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks whether a character is ascii or not. */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
