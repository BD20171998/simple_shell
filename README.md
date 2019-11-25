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
