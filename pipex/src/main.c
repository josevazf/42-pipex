/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:14:52 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/07 15:12:16 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp) 
{
	//char 	**clean_argv;
	char	**clean_envp;
	char	**cmd;
	char	*cmd_path;
	int 	i;

	i = 0;
	if (argc != 2)
	{
		printf("Bad arg usage");
		return (1);
	}
	
	clean_envp = ft_parse_envp(envp);
	cmd = ft_split(argv[1], ' '); // alterar para 1
	cmd_path = get_cmd_path(clean_envp, cmd[0]);
	
	i = 0;
	while (clean_envp[i])
	{
		printf("envp[%d]: %s\n", i, clean_envp[i]);
		i++;
	}

	if (execve(cmd_path, cmd, envp) == -1)
	{
		return (2);
	}
}