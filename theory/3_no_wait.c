#include <fcntl.h> // pid_t
#include <stdio.h>
#include <stdlib.h> // EXIT Status
#include <unistd.h>

int		main(void) 
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		printf("Child: I'm the child, my internal pid is %d.\n", pid);
		sleep(1); // Sleep for 1 second
		printf("Child: Done!\n");
	}
	else if (pid > 0)
	{
		printf("Parent: I'm the parent, my child's pid is %d.\n", pid);
		printf("Parent: Done!\n");
	}
	return (0);
}

/* Our command prompt returns before the child process is even terminated. 
This is because our shell is only waiting for our parent process (its child) to finish. 
It doesn’t know or care about our program’s child process (its grand-child). 
In a case like this, when the parent finished without waiting for its child, 
the child becomes an orphan process. It is then adopted by init (its PPID becomes 1) 
and is quickly eliminated from the system. */