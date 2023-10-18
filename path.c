#include "shell.h"
/**
 * exec - execute a command in a child process.
 * @child_pid: this is the Process Identifier (ID) of the child.
 * @arr: array of strings for the command and its arguments.
 * @cnt: number of arguments in @arr.
 *
 * Return: exit the status of the child process.
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
 *way - This function handles path.
 *Takes: the command that was typed in the shell, checks
 *in which directory inside PATH the command is located and
 *executes the command.
 *@dil: an array of string pointers.
 *@cnt: the loop counter from getline
 *Return: return concatenated string; otherwise: NULL.
 */
int way(char **dil, int cnt)
{
	char *path_begin = _genv("PATH");
	char *path_get = stringdup(path_begin);
	char *tokn, *pointer = dil[0], *open;
	pid_t child_pid = 0;
	int ex_status = 0;

	if (_how(dil[0]) == 0)
	{
		if (access(dil[0], X_OK) == 0)
		{
			ex_status = exec(child_pid, dil, cnt);
			free(path_get);
		}
		else
		{
			error(dil[0], cnt, 1);
			free(path_get);
		}
		return (ex_status);
	}
	else
	{
		tokn = strtok(path_get, ":");

		while (tokn != NULL)
		{
			open = str_concat(tokn, pointer, 1);
			if (_how(open) == 0)
			{
				if (access(open, X_OK) == 0)
				{
					dil[0] = open;
					ex_status = exec(child_pid, dil, cnt);
					free(open);
					free(path_get);
					return (ex_status);
				}
				else
				{
					/* access is denied */
					error(dil[0],  cnt, 1);
					return (2);
				}
			}

			tokn = strtok(NULL, ":");
			free(open);
		}
		free(path_get);
		error(dil[0], cnt, 0);
	}
	return (127);
}
