/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_using_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:31:32 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/09/04 11:36:13 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> // pid_t
#include <stdio.h>
#include <stdlib.h> // EXIT Status
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
	pid_t pid;
	int arr[] = { 1, 2, 3, 4, 1, 2 };
	int fd[2];
	int start, end;
	int arrSize;
	int sum;
	int i;

	arrSize = sizeof(arr) / sizeof(int);
	sum = 0;
	
	
	if (pipe(fd) == -1)
	{
		printf("Failed creating pipe!");
		return (1);
	}

	pid = fork();
	if (pid == -1)
	{		
		printf("Failed creating fork!");
		return (2);
	}
	
	// Set Child sum
	if (pid == 0)
	{
		start = 0;
		end = start + arrSize / 2;
	}
	// Set Parent sum
	else
	{
		start = arrSize / 2;
		end = arrSize;	
	}
	while (i < end)
	{
		sum += arr[i];
		i++;
	}

	printf("Partial sum: %d\n", sum);
	
	if (pid == 0) 
	{
		close(fd[0]); // fd[0] is the read end
		write(fd[1], &sum, sizeof(sum)); // fd[1] is the write end
		close(fd[1]); // fd[1] is the read end
	}
	else
	{
		int sumFromChild;
		close(fd[1]);
		read(fd[0], &sumFromChild, sizeof(sumFromChild));
		close(fd[0]);
		
		int totalSum = sum + sumFromChild;
		printf("Total sum is %d\n", totalSum);
		wait(NULL);
	}

	
}