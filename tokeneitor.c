#include "main.h"
/**
* tokeneitor - Functions that divides the input in strings.
* @input: The input.
* Return: *token, an array of strings.
*/
char **tokeneitor(char *input)
{
	int cwords = input[0] == ' ' || input[0] == '\n' || input[0] == '\t' ? 0 : 1;
	char **token = NULL, *x;
	int l = 0, word = 0;

	while (input[l] != '\0')
	{
		if (input[l] == ' ' || input[l] == '\t' || input[l] == '\n')
		{
			if (input[l + 1] != ' ' && input[l + 1] != '\t' && input[l + 1] != '\n')
				cwords++;
		}
		l++;
	}
	token = malloc((sizeof(char *)) * cwords);
	if (!(token))
	{
		return (NULL);
	}

	x = strtok(input, "\n\t ");
	token[0] = strdup(x);
	word = 1;
	for (; word < cwords; word++)
	{
		x = NULL;
		x = strtok(NULL, "\n\t ");
		if (!x)
			break;
		token[word] = strdup(x);
	}
	token[cwords - 1] = NULL;
	return (token);
}
