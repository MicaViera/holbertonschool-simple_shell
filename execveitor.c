#include "main.h"
/**
 * execveitor - Function that executes and forks.
 * @comand: The comand.
 * @argv: The arguments.
 * Return: The state of the system call execve.
*/
int execveitor(char *comand, char **argv)
{
	int state = 0;
	char *path = patheitor("PATH");
	char *pathito = NULL;
	pid_t pid;
	struct stat valid;

	if (stat(comand, &valid) == 0)
	{
		pid = fork();
		if (pid < 0)
			perror("Error");
		else if (pid == 0)
		{
			if (execve(comand, argv, environ) == -1)
				perror("Error");
		}
		else
			wait(&state);
	}
	else
	{
		pid = fork(), pathito = findex_path(argv[0], path);
		if (pid == 0)
		{
			if (execve(pathito, argv, environ) == 1)
			{
				free(pathito);
				perror("Error");
				exit(1);
			}
		}
		else
			wait(&state);
	}
	return (WEXITSTATUS(state));
}
