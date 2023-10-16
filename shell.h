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
*Struct - This is used to create ennvironmental variables
*@environ_list - The alias for struct
*@str: string - This allocates memory
*@node: this is the pionter to the next node
*
* Description:  Node structure of singly linked list
*/
typedef struct environ_list
{
	char *str;
	struct environ_list *node;
} env_list;
extern char **environ;
void sighand(int signum);
int exec(pid_t child_pid, char **arr, int cnt);
int way(char **dil, int cnt);
char *_genv(const char *var);
int _how(char *data);
int way(char **dil, int cnt);
unsigned int get_pid(void);
unsigned int get_ppid(void);
char *stringdup(const char *str);
int _strlen(char *s);
int str_comp(char **arr, int size);
void env(void);
char *str_concat(char *s1, char *s2, int flag);

