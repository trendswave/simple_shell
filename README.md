# C Simple Shell
# progresss......
we wil continually update the project ........


## Resources:books:
_Read or watch:_
* [Unix Shell](https://en.wikipedia.org/wiki/Unix_shell)
* [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)* [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
* [Everything you need to know to start coding your own shell](https://intranet.hbtn.io/concepts/64)

_man or help:_
* ```man_1_simple_shell``` (Run ```man_1_simple_shell``` as well)
---
## Learning Objectives:bulb:

At the end of this project, you are expected to be able to [explain to anyone](https://fs.blog/2012/04/feynman-technique/), _without the help of Google:
### General

* Who designed and implemented the original Unix operating system
* Who wrote the first version of the UNIX shell
* Who invented the B programming language (the direct predecessor to the C programming language)
* Who is Ken Thompson
* How does a shell work
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of main
* How does the shell use the PATH to find the programs
* How to execute another program with the execve system call
* How to suspend the execution of a process until one of its children terminates
* What is EOF / “end-of-file”?

## Requirements
### General

* Allowed editors: ```vi```, ```vim```, ```emacs```
* All your files will be compiled on Ubuntu 14.04 LTS
* Your C programs and functions will be compiled with ```gcc 4.8.4``` using the flags ```-Wall``` ```-Werror``` ```-Wextra``` and ```-pedantic```
* All your files should end with a new line
*  A ```README.md``` file, at the root of the folder of the project is mandatory
* Your code should use the ```Betty``` style. It will be checked using ```betty-style.pl``` and ```betty-doc.pl```
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to why

# More Info
## Output

* Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.

* The only difference is when you print an error, the name of the program must be equivalent to your ```argv[0]```

#Error with program sh:

$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$

#Error with program hsh:

$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$

### List of allowed functions and system calls
* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* fork (man 2 fork)
* free (man 3 free)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)
* _exit (man 2 _exit)
* isatty (man 3 isatty)
* fflush (man 3 fflush)


## compilation
Your shell will be compiled this way

gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

## Testing 

<h3>your shell should work like this in the interactive mode:</h3>

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

<h3>But also in non_interactive mode:</h3>

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

## How to use

Run hsh as an executable file. ./hsh 

## Authors

([Babatunde Oladunjoye](https://twitter.com/oladunjoye23301))🙏
<br>
([Paul Micheal](https://twitter.com/trendswave_c))🙏
