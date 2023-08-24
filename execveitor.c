#include "main.h"
/**
 * execveitor - Function that executes and forks.
 * @comand: The comand.
 * @argv: The arguments.
 * Return: The state of the system call execve.
*/
int execveitor(char *comand, char **argv)
{
	int state;
	char *path = patheitor("PATH=");
	char *pathito;
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
		pathito = findex_path(comand, path);
		if (stat(pathito, &valid) == 0)
		{
			pid = fork();
			if (pid == 0)
			{
				if (execve(pathito, argv, environ) == -1)
					free(pathito);
			}
			else
				free(pathito), wait(&state);
		}
		else
			fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
	}
	return (WEXITSTATUS(state));
}
