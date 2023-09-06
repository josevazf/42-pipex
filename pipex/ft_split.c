/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:22:34 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/06 10:37:59 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_isdelimiter(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_countwords(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		while (ft_isdelimiter(str[i]) && str[i])
			i++;
		if (!ft_isdelimiter(str[i]) && str[i])
			count++;
		while (!ft_isdelimiter(str[i]) && str[i])
			i++;
	}
	return (count);
}

char *ft_substring(int start, int end, char *str)
{
	int 	size;
	int 	i; 
	char 	*subs; 
	
	i = 0;
	size = (end - start) + 1;
	subs = malloc((size + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	while (i < size)
	{
		subs[i] = str[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);	
}

char **ft_split(char *str)
{
	char 	**split;
	int		words = ft_countwords(str) + 1;
	int 	i = 0;
	int 	j = 0;
	int 	start = 0;
	int		end = 0;
	
	split = malloc(words * sizeof(char *));
	if (!split)
		return (NULL);	
	while (str[i])
	{
		if (j == words - 1)
			return (split);
		while (ft_isdelimiter(str[i]) && str[i])
			i++;
		start = i;
		while (!ft_isdelimiter(str[i]) && str[i])
			i++;
		end = i - 1;
		split[j] = ft_substring(start, end, str);
		j++;
	}
	split[j] = NULL;
	return (split);
}
