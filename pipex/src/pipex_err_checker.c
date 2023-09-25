/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_err_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:01:13 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/25 15:16:06 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *msg, int exit_code)
{
	perror(msg);
	exit(exit_code);
}

void	free_tab_and_exit(char **strs, char *message)
{
	ft_free_matrix(strs);
	ft_error(message, ERROR);
}
