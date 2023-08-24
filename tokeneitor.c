#include "main.h"
/**
* tokeneitor - Functions that divides the i in strings.
* @i: The input.
* Return: *token, an array of strings.
*/
char **tokeneitor(char *i)
{
	char **token = NULL;
	int l = 0, word = 0;

	while (i[l] != '\0')
	{
		if (i[l] == ' ' || i[l] == '\t' || i[l] == '\n' || i[l == ':'])
		{
			word++;
		}
		l++;
	}
	word += 1;
	token = malloc((sizeof(char *)) * (word + 1));
	if (!(token))
	{
		free(i);
		return (NULL);
	}
	token[0] = strtok(i, "\n\t: ");
	l = 1;
	while (l < word)
	{
		token[l] = strtok(NULL, " \n\t:");
		l++;
	}
	token[l] = NULL;
	return (token);
}

/**
 * free_grid - free up 2 grid
 * @grid: Array of pointers.
 */
void free_grid(char **grid)
{
	int i = 0;

	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
