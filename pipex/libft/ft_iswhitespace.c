/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:58:28 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/19 09:58:53 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks whether a character is whitespace or not (space, tab...). */

#include "libft.h"

int		ft_iswhitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}