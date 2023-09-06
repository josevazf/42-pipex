/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:42 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/06 11:16:56 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		ft_strlen(char *str)
{
	int i;
	i = 0;
	
	while (str[i])
		i++;
	return (i);
}

char 	**ft_clean_argv(int argc, char **argv)
{	
	char 	**clean_argv;
	int		i;
	
	i = 0;
	clean_argv = malloc((argc - 1)  * sizeof(char *));
	while (i < argc - 1)
	{	
		clean_argv[i] = malloc(ft_strlen(argv[i + 1] + 1) * sizeof(char));
		clean_argv[i] = argv[i + 1];
		i++;		
	}
	return (clean_argv);
}

/* char	**ft_parse_envp(char **envp)
{
	
	
} */