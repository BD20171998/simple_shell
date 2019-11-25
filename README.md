## Simple Shell

### Description

The Simple Shell is a simple UNIX command interpreter written entirely in C. The
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

### Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

### List of Allowed Functions & System Calls

* access (check real user's permissions for a file)
* execve (execute program)
* exit (cause normal process termination)
* fork (create a child process)
* free (free dynamic memory)
* getline (delimited string input)
* isatty (test whether a file descriptor refers to a terminal)
* malloc (allocate memory)
* perror (print a system error message)
* read (read from a file descriptor)
* stat (__xstat) (man 2 stat)
* strtok (extract tokens from strings)
* wait (wait for process to change state)
* write (write to a file descriptor)

### Usage

The shell works like this in interactive mode:

```bash
$ ./hsh
##---> /bin/ls
hsh shell.c path.c README.md
```

```bash
##---> ls -l
-rwxrwxr-x 1 vagrant vagrant 14136 Nov 24 21:42 hsh
-rw-rw-r-- 1 vagrant vagrant   863 Nov 24 21:42 shell.c
-rw-rw-r-- 1 vagrant vagrant   784 Nov 24 01:02 path.c
-rw-rw-r-- 1 vagrant vagrant  1449 Nov 22 23:48 README.md
```

```bash
##---> pwd
/home/vagrant/simple_shell
```

```bash
##---> exit
$
```



The shell works like this in non-interactive mode:

```bash
$ echo "/bin/ls" | ./hsh
hsh shell.c path.c README.md test_ls
$
$ cat test_ls
/bin/ls
/bin/ls
$
$ cat test_ls | ./hsh
hsh shell.c path.c README.md test_ls
hsh shell.c path.c README.md test_ls
$
```

### Built-Ins

The simple shell has support for the following built-in commands:

| Command             | Definition                                                                                |
| ------------------- | --------------------------------------------------------------------------------
| env                 | Prints the environment
| exit                | Exits the shell


### Flowchart

![Image of Flowchart](Image Link of Flowchart goes here)

### Authors

[Ariana Bibiano](https://github.com/ariana124)

[Erika Caoili](https://github.com/ecaoili24)

[Robert Deprizio](https://github.com/BD20171998)
