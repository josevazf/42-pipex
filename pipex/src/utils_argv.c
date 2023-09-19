/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:42 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/19 12:20:50 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char 	**ft_clean_argv(int argc, char **argv)
{	
	char 	**clean_argv;
	int		i;
	
	i = 0;
	clean_argv = malloc((argc - 1) * sizeof(char *));
	if (clean_argv == NULL)
		return (NULL);
	while (i < argc - 1)
	{	
		clean_argv[i] = malloc(ft_strlen(argv[i + 1] + 1) * sizeof(char));
		if (clean_argv[i] == NULL)
			return (NULL);
		clean_argv[i] = argv[i + 1];
		i++;		
	}
	return (clean_argv);
}

// Find 'PATH=' in env file and return the paths delimited by ':'
char	**ft_parse_envp(char **envp)
{
	char 	*envp_dup;
	char	**paths;
	int 	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break;
		i++;
	}
	if (envp[i] == NULL)
		return (NULL);
	envp_dup = ft_strdup(envp[i] + 5);
	if (envp_dup == NULL)
		return (NULL);
	paths = ft_split(envp_dup, ':');
	free(envp_dup);
	if (paths == NULL)
		return (NULL);
	return (paths);	
}

char	*get_cmd_path(char **envp_paths, char *cmd)
{
	char	*temp_path;
	char	*new_path;
	int 	i;
	
	i = 0;
	while(envp_paths[i])
	{
		temp_path = ft_strjoin(envp_paths[i], "/");
		if (temp_path == NULL)
			return (NULL);
		new_path = ft_strjoin(temp_path, cmd);
		free (temp_path);
		if (new_path == NULL)
			return (NULL);
		if (access(new_path, X_OK) == 0)
			return (new_path);
		free(new_path);
		i++;		
	}
	return (NULL);
}

