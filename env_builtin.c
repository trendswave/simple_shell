#include "shell.h"

/**
 * env - to print the environment variables in the format "variable = value"
 * Description: function iterates through the environ array
 *
 * Return:this function does not returns a value.
 */

void env(void)
{
	int j = 0;

	while (environ[j])
	{
		/* print in form of "variable = value" */
		write(STDOUT_FILENO, environ[j], _strlen(environ[j]));
		j++;
		write(STDOUT_FILENO, "\n", 1);
	}
}
