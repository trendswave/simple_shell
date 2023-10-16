#include "shell.h"
/**
 *exec - fork, execute, wait function
 * @child_pid: child process
 * @arr: double pointer to array of strings
 * @cnt: the number of loops from getline
 * Return: 0 or -1
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
