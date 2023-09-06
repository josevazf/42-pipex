/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:36:44 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/04/19 14:18:46 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Returns a new string, the result of the concatenation of ’s1’ and ’s2’. */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1[++i])
		join[i] = s1[i];
	while (s2[++j])
		join[j + i] = s2[j];
	join[i + j] = '\0';
	return (join);
}
