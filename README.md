## Simple Shell

### Description

Simple shell is a simple UNIX command interpreter written in C. The code for
this project was tested in Ubuntu 14.04 LTS and compiled with gcc 4.8.4. The
program runs based on bash commands obtained from the input stream by the user.
Any text seperated by a single space is considered to be an argument. The
respective command typed by the user is then executed as if in a UNIX shell.

### How Does it Work

The program first prints the shell prompt and awaits the user's input. The input
is then parsed into seperate arguments using a single space as a delimiter.
Built-ins such as **env** and **exit** are handled seperately (see below) when
the user inputs such commands.

The new line character is removed via the **no_nl** function described in the
*functions* section below.

After the input has been checked for built-ins and potential keystroke errors
from the input stream, a child process is created via the *fork* function. The
user's arguments are passed to *execvp* and the command is then executed if the
command exists. Once the command executes if found, the child process ends with
the exit function.

Once the user exits the shell via the built-in *exit* or enters the end of file
value with *(Ctrl+D)* the program frees the remaining memory allocated during
the course of its run and exits.

> **Built-ins**
>

 - env: Prints the current environment

 - exit: Exits the shell

> **Functions**
>

