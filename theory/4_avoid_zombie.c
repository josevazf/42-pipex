#include <fcntl.h> // pid_t
#include <stdio.h>
#include <stdlib.h> // EXIT Status
#include <unistd.h>

int	main(void)
{
	pid_t	pid;
	
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		printf("Child: I'm the child, my internal pid is %d.\n", pid);
		printf("Child: Done!\n");
	}
	else if (pid > 0)
	{
		printf("Parent: I'm the parent, my child's pid is %d.\n", pid);
		while (1) // Infinite loop, the parent will never end!
			sleep(1);
	}
	return (0);
}

