#include "shell.h"
/**
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
