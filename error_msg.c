#include "shell.h"
/**
*error - This function returns custom error messages
*@str: The argument at index 0
*@ln: Line count from getline function
*@flag: To determine which error message to output
*/

void error(char *str, int ln, int flag)
{
	char *counter = NULL;
	char *fcn = _genv("_");
	counter = ascii(ln);
	write(STDERR_FILENO, fcn, _strlen(fcn));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, counter, _strlen(counter));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str, _strlen(str));
	if (flag == 0)
		write(STDERR_FILENO, ": No such file or directory\n", 13);
	else if (flag == 1)
		perror(" ");
	free(counter);
}
