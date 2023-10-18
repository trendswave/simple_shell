#include "shell.h"

/**
* sighand -This function handlse ctrl+c(EOF)
* @signum: The signal numbe to be processed
*/
void sighand(int signum)
{
	(void)signum;
	write(1, "\n$ ", 3);
}
/**
* main - The entry point of the  simple shell program
* Return: 0 always successful
*/
int main(void)
{
	/*Proces ID and Parent PID int*/
	ssize_t read = 0;
	char *buff = NULL, **arr;
	size_t size = 0;
	int result, tok_size = 0, len = 0, counter = 0;
	int ex_flag = 0;

	while (1)
	{
		size = 0;
		buff = NULL;
		if (isatty(0))
			write(STDIN_FILENO, "$ ", 2);
		signal(SIGINT, sighand);
		read = getline(&buff, &size, stdin);
		counter++;
		if (read == -1)
		{
			if (isatty(0))
				write(STDIN_FILENO, "\n", 1);
			free(buff);
			return (0);
		}
		if (read == 0)
		{
			if (isatty(0))
			{
				write(STDIN_FILENO, "\n", 1);
				continue;
			}
		}
		if (buff && buff[0] != '\n')
		{
			/* checks the  length of  input */
			len = _strlen(buff);
			if (buff[len - 1] == '\n')
				buff[len - 1] = '\0';
			/* check for tok input */
			tok_size = tstring(buff);
			if (tok_size == -1)
				break;
			if (tok_size == 0)
				continue;
			/* array of tokens*/
			arr = tokn(buff);
			/* check if  'env', 'exit', or '.'command  is typed*/
			result = str_comp(arr, tok_size);
			if (result == 0)
			{
				free(arr);
				free(buff);
				exit(ex_flag);
			}
			ex_flag = 0;
			if (result == 2)
			{
				free(arr);
				free(buff);
				continue;
			}
			else if (result == 1)
			{
				env();
				free(arr);
				free(buff);
				continue;
			}
			/*  path function input check */
			/*exists, permissions, or execute */
			ex_flag = way(arr, counter);
		}
		if (buff && buff[0] == '\n')
		{
			free(buff);
			continue;
		}
		free(buff);
		free(arr);
	}
	return (0);
}
