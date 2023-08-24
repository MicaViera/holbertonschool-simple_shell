#include "main.h"
/**
* main - Function that prints $ and waits the command then prints it.
* Return: 0.
*/
int main(void)
{
	size_t len;
	ssize_t read;
	char *line = NULL, **atokens = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			exit(0);
		}
		atokens = tokeneitor(line);
		if (atokens == NULL || atokens[0] == NULL)
		{
			free(atokens);
			continue;
		}
		if (strcmp(atokens[0], "exit") == 0)
		{
			break;
		}
		if (execveitor(atokens[0], atokens) == -1)
			continue;
		if (read == -1)
		{
			free(line);
		}
		free(atokens);
	}
	if (atokens)
		free_grid(atokens);
	return (0);
}
