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
		if (access(dil[0], X_OK) == 0)
		{
			ex_status = exec(child_pid, dil, cnt);
			free(path_copy);
		}
		else
		{
			error(dil[0], cnt, 1);
			free(path_copy);
		}
		return (ex_status);
	}
	else
	{
		token = strtok(path_copy, ":");

		while (token != NULL)
		{
			cats = str_concat(token, ptr, 1);
			if (_how(cats) == 0)
			{
				if (access(cats, X_OK) == 0)
				{
					dil[0] = cats;
					ex_status = exec(child_pid, dil, cnt);
					free(cats);
					free(path_copy);
					return (ex_status);
				}
				else
				{
					/* files exist, but access is denied */
					error(dil[0], cnt, 1);
					return (2);
				}
			}

			token = strtok(NULL, ":");
			free(cats);
		}
		free(path_copy);
		error(dil[0], cnt, 0);
	}
	return (127);
}
