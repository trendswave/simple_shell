#include "shell.h"

/**
 * _genv - this searches for the environment variable.
 * @var: this is name of the environment variable to search.
 *
 * Return: this is the pointer to the value of the environment.
 * variable or NULL if variable is not found.
 */
char *_genv(const char *var)
{
	int j, k, ln = 0;

	while (var[ln] != '\0')
		ln++;

	if (ln == 0)
		return (NULL);

	for (j = 0 ; environ[j] != NULL ; j++)
	{
		for (k = 0 ; var[k] != '\0' ; k++)
		{
			if (environ[j][k] != var[k])
				break;
		}
		if (var[k] == '\0')
			return (environ[j] + k + 1);
	}
	return (NULL);
}
/**
 * _how - to check if a file or directory exists.
 * @data: this is the path to the file or directory to check.
 *
 * Return: returns zero(0) if the file or directory exists,
 * otherwise -1.
 */
int _how(char *data)
{
	struct stat status;

	while (data)
	{
		if (stat(data, &status) == 0)
		{
			return (0);
		}
		break;
	}
	return (-1);
}
