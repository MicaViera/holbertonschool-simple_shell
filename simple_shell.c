#include "main.h"
/**
* main - Function that prints $ and waits the command then prints it.
* Return: 0.
*/
int main(void)
{
	size_t len = 0;
	ssize_t read;
	char *line = NULL;
	char *p = "$ ", **atokens = NULL;
	int iteractive = isatty(STDERR_FILENO);

	while (1)
	{
		if (iteractive == 1)
			printf("%s", p);

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			return (-1);
		}
		atokens = tokeneitor(line);
		if (strcmp(line, "exit") == 0)
			break;
		if (execveitor(atokens[0], atokens) == 1)
			continue;
	}
	free(line);
	return (0);
}
