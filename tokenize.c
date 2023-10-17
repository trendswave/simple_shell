#include "shell.h"
/**
* tstring - number of tokens from getline
* @link: string to count number of tokens
* Return: number of tokens
*/
int tstring(char *link)
{
	int tsize = 0, j = 0;
	if (!link)
	{
		write(STDIN_FILENO, '\0', 1);
		return (-1);
	}
	while (link[j] != '\0')
	{
		/* check 1st index if it is a tab */
		if (link[j] == '\t')
			link[j] = ' ';
		/* check if next index is a tab */
		if (link[j + 1] == '\t')
			link[j + 1] = ' ';
		/**
		 *check if it is not a space (it's a char)
		 * AND the index after is either space or null,
		 *count it as a token
		 */
		if (link[j] != ' ' && (link[j + 1] == ' ' || link[j + 1] == '\0'))
			tsize++;
		j++;
	}
	return (tsize);
}
/**
* tokn - function to get tokens from string
* and store in an array
* @link: string to tokenize
* Return: array
*/
char **tokn(char *link)
{
	char *tok, **logic;
	int j = 0, letters;

	letters = tstring(link);
	if (!letters)
		return (NULL);
	logic = malloc(sizeof(char *) * (letters + 1));
	if (!logic)
		return (NULL);
	tok = strtok(link, " \t");
	while (tok != NULL)
	{
		logic[j] = tok;
		tok = strtok(NULL, " \t");
		j++;
	}
	logic[j] = NULL;
	return (logic);
}
