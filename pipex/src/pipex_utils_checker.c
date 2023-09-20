/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:01:13 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/20 11:58:56 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str, int exit_code)
{
	perror(str);
	exit(exit_code);
}

void	free_tab_and_exit(char **strs, char *message)
{
	ft_free_matrix(strs);
	ft_error(message, 1);
}

int	check_args(int argc)
{
	if (argc != 2)
	{
		ft_printf("Usage:\n");
		ft_printf("./pipex infile cmd1 cmd2 outfile\n");
		exit(1);
	}
	return (0);
}
