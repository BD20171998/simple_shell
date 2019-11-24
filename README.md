## Simple Shell

### Description

Simple shell is a simple UNIX command interpreter written entirely in C. The
program runs based on bash commands obtained from the input stream by the user.
Any text seperated by a single space is considered to be an argument. The
respective command typed by the user is then executed as if in a UNIX shell.

### Requirements

* Allowed editors: vi, vim, or emacs
* All files were compiled on Ubuntu 14.04 LTS
* Programs and functions were compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All files should end with a new line
* Code should use the Betty style. It is checked using betty-style.pl and betty-doc.pl
* No more than 5 functions per file
* All header files should be include guarded
* System calls are only used when needed

### List of Allowed Functions & System Calls

* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)

### How Does it Work

The program first prints the shell prompt and awaits the user's input. The input
is then parsed into seperate arguments using a single space as a delimiter.
Built-ins such as **env** and **exit** are handled seperately (see below) when
the user inputs such commands.

The new line character is removed via the **no_nl** function described in the
*functions* section below.

After the input has been checked for built-ins and potential keystroke errors
from the input stream, a child process is created via the **fork** function. The
user's arguments are passed to **execve** and the command is then executed if the
command exists. Once the command executes if found, the child process ends with
the exit function.

Once the user exits the shell via the built-in **exit** or enters the end of file
value with **(Ctrl+D)** the program frees the remaining memory allocated during
the course of its run and exits.

### Built-Ins

The simple shell has support for the following built-in commands:

| Command             | Definition                                                                                |
| ------------------- | --------------------------------------------------------------------------------
| env                 | Prints the environment                                                                                  
| exit                | Exits the shell                                                                    


### Authors

[Ariana Bibiano](https://github.com/ariana124)

[Erika Caoili](https://github.com/ecaoili24)

[Robert Deprizio](https://github.com/BD20171998)
