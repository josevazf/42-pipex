/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:50:10 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/04/19 14:32:38 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Returns a pointer to 'dest', which is a duplicate of the string 'src'. */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *str)
{
	char	*temp;

	temp = malloc(ft_strlen(str) + 1);
	if (temp != NULL)
	{
		ft_strcpy(temp, str);
		return (temp);
	}
	else
		return (NULL);
}
