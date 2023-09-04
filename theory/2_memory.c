/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_memory.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:56:43 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/04 09:18:34 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> // pid_t
#include <stdio.h>
#include <stdlib.h> // EXIT Status
#include <unistd.h>

// Child process routine:
void	child_routine(pid_t pid, int *nb)
{
	printf("Child: Hi! I'm the child. PID received from fork = %d\n", pid);
	printf("Child: The number is %d\n", *nb);
	
}

// Parent process routine:
void	parent_routine(pid_t pid, int *nb)
{
	printf("Parent: I'm the parent. PID received from fork = %d\n", pid);
	printf("Parent: The number is %d\n", *nb);
	*nb *=2;
	printf("Parent: The modified number is %d\n", *nb);
}

int		main(void)
{
	pid_t	pid; // Stores the return value of fork
	int		nb;  // Stores and integer
	
	nb = 42;
	printf("Before fork, the number is %d\n", nb);
	pid = fork(); // Creating the child process
	if (pid == -1)
		return (EXIT_FAILURE);
	else if (pid == 0) // The pid is 0, this is the child process
		child_routine(pid, &nb);
	else if (pid > 0) // The pid is > 0, this is the parent
		parent_routine(pid, &nb);
	return (EXIT_SUCCESS);
}

/* Here, after the child process’ creation, 
the parent doubles the value of the given number 
using a memory address pointer. But the child prints 
the number’s original value, unaware of the parent’s modification. */