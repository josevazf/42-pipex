/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdelimiter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:59:48 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/19 10:00:56 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks if character 'c' is the same as char 's'. */

#include "libft.h"

int		ft_isdelimiter(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}