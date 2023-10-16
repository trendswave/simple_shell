#ifndef _SHELL_H_
#define _SHELL_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
/**
* 
*
*
*
*/
typedef struct environ_list
{
		char *str;
			struct environ_list *next;
} env_list;

void sighand(int signum);
int exec(pid_t child_pid, char **arr, int cnt);
int way(char **dil, int cnt);
char *_genv(const char *var);
int _how(char *data);
int way(char **dil, int cnt)
