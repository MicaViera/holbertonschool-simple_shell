#include "main.h"
/**
 * patheitor - Function that gets the PATH.
 * @fpath: The name of the enviroment variable to find.
 * Return: The PATH and in failure NULL.
*/
char *patheitor(const char *fpath)
{
	size_t lenght = strlen(fpath);
	int i = 0;
	char *current_env = NULL;

	for (; environ[i] != NULL; i++)
	{
		current_env = environ[i];

		if (strncmp(current_env, fpath, lenght) == 0 && current_env[lenght] == '=')
			return (&current_env[lenght + 1]);
	}
	return (NULL);
}

/**
 * findex_path - Function that finds the executable path of the given command.
 * @command: The command.
 * @path: The PATH.
 * Return: Apointer with the executable PATH and in failure NULL.
*/
char *findex_path(const char *command, const char *path)
{
	char *copy_path = strdup(path);
	char *token = strtok(copy_path, ":");
	char commandpath[1024];

	while (copy_path != NULL)
	{
		sprintf(commandpath, "%s/%s", token, command);
		if (access(commandpath, X_OK) == 0)
		{
			free(copy_path);
			return (strdup(commandpath));
		}
		token = strtok(NULL, ":");
	}
	free(copy_path);
	return (NULL);
}
/**
* enveneitor - function that prints the environment
*/
void enveneitor(void)
{
	char **penv;

	for (penv = environ; *penv != NULL; penv++)
	{
		printf("%s\n", *penv);
	}
}
