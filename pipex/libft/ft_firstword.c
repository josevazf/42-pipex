/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_firstword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:08:19 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/19 11:25:50 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Gets the first word from passed string. */

#include "libft.h"

char	*ft_firstword(char *argv)
{
	char 	*first_word;
	int		start;
	int		i;

	i = 0;
	if (argv == NULL)
		return (NULL);
	while (ft_iswhitespace(argv[i]) && argv[i])
		i++;
	start = i;
	while (!ft_iswhitespace(argv[i]) && argv[i])
		i++;
	first_word = ft_substr(argv, start, (i - start));
	return (first_word);
}