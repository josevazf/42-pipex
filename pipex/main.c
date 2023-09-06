/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:14:52 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/06 20:04:44 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp) 
{
	char 	**clean_argv;
	char	**clean_envp;
	char	*cmd;
	int 	i;

	i = 0;
	if (argc != 3)
	{
		printf("Bad arg usage");
		return (1);
	}
	
	clean_argv = ft_clean_argv(argc, argv);
	clean_envp = ft_parse_envp(envp);
	cmd = get_cmd_path(clean_envp, clean_argv[0]);
	
	while (clean_argv[i])
	{
		printf("argv[%d]: %s\n", i, clean_argv[i]);
		i++;
	}
	i = 0;
	while (clean_envp[i])
	{
		printf("envp[%d]: %s\n", i, clean_envp[i]);
		i++;
	}

	/* 	if (execve(cmd, clean_argv, envp) == -1)
	{
		return (2);
	} */
}