/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:31:23 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/19 10:49:05 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strtrim_l(char *bufftxt)
{
	char	*final_line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!bufftxt[i])
		return (NULL);
	while (bufftxt[i] && bufftxt[i] != '\n')
		i++;
	final_line = malloc(sizeof(char) * (i + 2));
	if (!bufftxt)
		return (NULL);
	j = -1;
	while (++j <= i)
		final_line[j] = bufftxt[j];
	final_line[j] = '\0';
	return (final_line);
}

char	*ft_strtrim_r(char *bufftxt)
{
	char	*next_line;
	size_t	i;
	size_t	j;

	i = 0;
	while (bufftxt[i] && bufftxt[i] != '\n')
		i++;
	if (!bufftxt[i])
	{
		free(bufftxt);
		return (NULL);
	}
	next_line = malloc(sizeof(char) * (ft_strlen(bufftxt) - i));
	if (!bufftxt)
		return (NULL);
	j = -1;
	while (++i < ft_strlen(bufftxt))
		next_line[++j] = bufftxt[i];
	next_line[++j] = '\0';
	free(bufftxt);
	return (next_line);
}
