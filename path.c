#include "shell.h"
/**
 *
 *
 *
 *
 *
 */
int exec(pid_t child_pid, char **arr, int cnt)
{
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork() error: ");
		return (-1);
	}
	if (child_pid == 0)
	{
		if (execve(arr[0], arr, NULL) == -1)
		{
			if (arr[0][0] == '/')
			{
				error(arr[0], cnt, 1);
				exit(126);
			}
			error(arr[0], cnt, 0);
			exit(status);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			const int ex_status = WEXITSTATUS(status);

			return (ex_status);
		}
	}
	return (0);
}
/**
 *way - Thos is function that handles path 
 *Takes the command that was typed in the shell, checks
 *in which directory inside PATH the command is located and
 *executes the command.
 *@dil: an array of string pointers.
 *@cnt: the loop counter from getline
 *Return: return concatenated string; otherwise: NULL.
 */
 int way(char **dil, int cnt)
{
	char *path_original = _genv("PATH");
	char *path_copy = stringdup(path_original);
	char *token, *ptr = dil[0], *cats;
	pid_t child_pid = 0;
	int ex_status = 0;
	
	if (_how(dil[0]) == 0)
	{
		if (_how(dil[0]) == 0)
