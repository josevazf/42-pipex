/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_file_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:25:15 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/20 11:09:57 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	open_file(char *file_name, int file_type)
{
	int	file_fd;

	if (file_type == IN_FILE)
		file_fd = open(file_name, O_RDONLY);
	if (file_type == OUT_FILE)
		file_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644); // owner r/w, group/others r
	if (file_fd == -1)
		ft_error("Infile error", 1);
	if (file_type == IN_FILE)
		dup2(file_fd, STDIN_FILENO);
	if (file_type == OUT_FILE)
		dup2(file_fd, STDOUT_FILENO);
	close(file_fd);
}

