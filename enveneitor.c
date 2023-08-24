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
	char *curre_env = NULL;

	for (; environ[i] != NULL; i++)
	{
		curre_env = environ[i];
		if (strncmp(curre_env, fpath, lenght) == 0)
			return (&curre_env[lenght + 1]);
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
	char **token = NULL;
	char commandpath[1024];
	int i = 0;

	token = tokeneitor(copy_path);
	if (!token)
		return (NULL);
	while (token[i] != NULL)
	{
		sprintf(commandpath, "%s/%s", token[i], command);
		if (access(commandpath, X_OK) == 0)
		{
			free(copy_path);
			free(token);
			return (strdup(commandpath));
		}
		else
			i++;
	}
	free(copy_path);
	free(token);
	return (NULL);
}
/**
* enveneitor - function that prints the environment
*/
void enveneitor(void)
{
	char **penv = NULL;

	for (penv = environ; *penv != NULL; penv++)
	{
		printf("%s\n", *penv);
	}
}
