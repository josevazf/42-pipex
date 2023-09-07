/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:14:52 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/07 13:21:48 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp) 
{
	char 	**clean_argv;
	char	**clean_envp;
	char	*cmd;
	char	*cmd_path;
	int 	i;

	i = 0;
	if (argc != 3)
	{
		printf("Bad arg usage");
		return (1);
	}
	
	clean_envp = ft_parse_envp(envp);
	cmd = get_first_word(clean_argv[0]);
	cmd_path = get_cmd_path(clean_envp, cmd);
	
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