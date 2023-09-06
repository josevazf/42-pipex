/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:14:52 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/06 11:17:47 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp) 
{
	char 	**clean_argv;
	int 	i;

	i = 0;
	if (argc != 3)
	{
		printf("Bad arg usage");
		return (1);
	}
	//char *cmd = "/usr/bin/ls";
	
	clean_argv = ft_clean_argv(argc, argv);
	while (clean_argv[i])
	{
		printf("argv[%d]: %s\n", i, clean_argv[i]);
		i++;
	}
	
/* 	if (execve(cmd, clean_argv, envp) == -1)
	{
		return (2);
	} */

	while (envp[i])
	{
		printf("envp[%d]: %s\n", i, envp[i]);
		i++;
	}
}