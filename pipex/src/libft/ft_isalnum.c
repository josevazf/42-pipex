/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:57:31 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/04/19 13:05:21 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks whether the argument passed is alphanumeric (alphabet or number). */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
