#include "shell.h"
/**
*str_concat -This concatenates two strings
* The returned pointer points to a newly allocated space in memory
* which contains the contents.
*
* @s1: modified string.
* @s2: appended string.
* @flag: flag for handling path or error function
* ls: linked_string works after the file has been concatenated.
*
* Return: Returns character
*/
char *str_concat(char *s1, char *s2, int flag)
{
	int len1 = 0, len2 = 0, i, j;

	char *ptr;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		if (s1 == NULL)
			return (NULL);
		*s1 = '\0';
	}
	if (s2 == NULL)
	{
		s2 = malloc(sizeof(char));
		if (s2 == NULL)
			return (NULL);
		*s2 = '\0';
	}
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;
	ptr = malloc(sizeof(char) * (len1 + len2 + 1 + flag));
	if (ptr == NULL)
		return (NULL);
	for (i = 0 ; s1[i] != '\0' ; i++)
		ptr[i] = s1[i];
	if (flag == 1)
	{
		ptr[i] = '/';
		i++;
	}
	for (j = 0 ; j < (len2 + 1) ; j++, i++)
		ptr[i] = s2[j];
	return (ptr);
}
