#include "shell.h"
/**
 * sighand - function to handle ctrl+c
 * @signum: signal number
 */
void sighand(int signum)
{
	(void)signum;
	write(1, "\n$ ", 3);
}
