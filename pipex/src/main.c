/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:14:52 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/19 12:18:41 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/* 
static void	ft_pipex(char **argv, char **path, char **envp)
{



	
} */

int main(int argc, char **argv, char **envp) 
{
	char	**envp_paths;
	char	*cmd;
	char	**cmd2;
	char	*cmd_path;
	int 	i;

	i = 0;
	if (argc != 2)
	{
		printf("Bad arg usage");
		return (1);
	}
	
	envp_paths = ft_parse_envp(envp); // Returns paths from env file
/* 	while (envp_paths[i])
	{
		ft_printf("envp[%d]: %s\n", i, envp_paths[i]);
		i++;
	} */
	cmd = ft_firstword(argv[1]); // Get the first command to run
	cmd2 = ft_split(argv[1], ' ');
	cmd_path = get_cmd_path(envp_paths, cmd);
	ft_printf("Final Command Path: %s\n", cmd_path);
	
/* 	i = 0;
	while (envp_paths[i])
	{
		printf("envp[%d]: %s\n", i, envp_paths[i]);
		i++;
	} */

	execve(cmd_path, cmd2, envp);
}
