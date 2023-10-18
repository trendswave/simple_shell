#include "shell.h"

/**
* stringdup - Return pointer to string (duplicate string)
* @str: The string that is to be duplicate
* Return: pointer to string or NULL if failure to allocate
*/
char *stringdup(const char *str)
{
	int i, j;
	char *ptr;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	;
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	for (j = 0; j < i; j++)
		ptr[j] = str[j];
	return (ptr);
}
/**
*_strlen - This function returns the length of a string
*@s: Variable that contains a character array to be counted
*Return: Length of the string
*/
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		continue;
	return (i);
}
/**
*str_comp - This function compare two strings
*@arr: String pointer arrays
*@size:Array size
*Return:Return 0 when successful, -1 when failed
*/
int str_comp(char **arr, int size)
{
	char *command[4] = {"exit", "env", ".", NULL};
	char *ptr = arr[0];
	int i = 0, j = 0, flag = 0;

	if (size != 1)
		return (-1);
	if (!ptr)
		return (1);
	while (command[i] != NULL)
	{
		j = 0;
		while (command[i][j] == ptr[j])
		{
			if (command[i][j] == '\0' || ptr[j] == '\0')
				break;
			j++;
		}
		if (command[i][j] == ptr[j])
			return (flag);
		i++;
		flag++;
	}
	return (-1);
}
