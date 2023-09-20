/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_err_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:01:13 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/20 14:53:39 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_args(int argc)
{
	if (argc != 5)
		ft_error("Usage:\n./pipex infile cmd1 cmd2 outfile\n", ERROR);
	return (0);
}

void	ft_error(char *str, int exit_code)
{
	perror(str);
	exit(exit_code);
}

void	free_tab_and_exit(char **strs, char *message)
{
	ft_free_matrix(strs);
	ft_error(message, ERROR);
}
