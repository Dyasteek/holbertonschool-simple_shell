![Simple Shell Banner](src/banner.png)
<h1>Simple Shell</h1>
Release date Aug 20, 2025

</p>
          </a>
          <a href="https://github.com/Dyasteek/holbertonschool-simple_shell/graphs/commit-activity" target="_blank">
               <img alt="commit_activity" src="https://img.shields.io/github/commit-activity/y/Dyasteek/holbertonschool-simple_shell" />
          </a>
          <a href="https://github.com/Dyasteek/holbertonschool-simple_shell/graphs/contributors" target="_blank">
               <img alt="contributors" src="https://img.shields.io/github/contributors/Dyasteek/holbertonschool-simple_shell" />
          </a>
          <a href="https://github.com/Dyasteek/simple_shell/blob/master/README.md" target="_blank">
               <img alt="Documentation" src="https://img.shields.io/badge/documentation-yes-brightgreen" />
          </a>
     </p>

## Table of Contents
* [Introduction](#Introduction)
  * What is Shell
  * What is it for
* [Project Information](#Project-Information)
    * Tasks
    * Enviroment
    * General requirements
* [Documentation](#Documentation)
    * Instalation
    * Files
* [Authors](#Authors)

## Introduction

### What is Shell
A **shell** is a command-line interpreter, it is the computer program that provides a user interface to access the services of the operating system. Depending on the type of interface they use, shells can be of various types, in this case, a shell program of the type **`sh`** ([Bourne Shell](https://en.wikipedia.org/wiki/Bourne_shell)) will be developed. Users typically interact with a shell using a [terminal emulator](https://en.wikipedia.org/wiki/Terminal_emulator) that is used for entering data into and displaying or printing data from, a computer or a computing system.

### What is it for
This consists of interpreting orders. It incorporates features such as process control, input/output redirection, law listing and reading, protection, communications, and a command language for writing batch programs or scripts. All Unix-type systems have at least one interpreter compatible with the Bourne shell. The Bourne shell program is found within the Unix file hierarchy at **`/bin/sh`**.

## Project Information

### Tasks

* 0. README, man_1_simple_shell, AUTHORS
* 1. Betty would be proud
* 2. Write a UNIX command line interpreter.
* 3. Handle command lines with arguments
* 4. Handle the PATH with correct call of fork.
* 5. Implement the exit built-in, that exits the shell without built-in arg.
* 6. Implement the env built-in, that prints the current environment.

### Enviroment

<!-- ubuntu -->
<a href="https://ubuntu.com/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=Ubuntu&color=E95420&logo=Ubuntu&logoColor=E95420&labelColor=2F333A" alt="Suite CRM"></a>
<!-- bash -->
<a href="https://www.gnu.org/software/bash/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=GNU%20Bash&color=4EAA25&logo=GNU%20Bash&logoColor=4EAA25&labelColor=2F333A" alt="terminal"></a>
<!-- c -->
<a href="https://www.cprogramming.com/" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=C%20Language&color=5C6BC0&logo=c&logoColor=A8B9CC&labelColor=2F333A" alt="C Low level programming language"></a>

<!-- vim -->
<a href="https://www.vim.org/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=Vim&color=019733&logo=Vim&logoColor=019733&labelColor=2F333A" alt="Suite CRM"></a>
<!-- git -->
<a href="https://git-scm.com/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=Git&color=F05032&logo=Git&logoColor=F05032&labelColor=2F333A" alt="git distributed version control system"></a>
<!-- github -->
<a href="https://github.com" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=GitHub&color=181717&logo=GitHub&logoColor=f2f2f2&labelColor=2F333A" alt="Github"></a>

Style guidelines: [Betty style](https://github.com/holbertonschool/Betty/wiki)

### General requirements
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using `betty-style.pl` and `betty-doc.pl`
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to [why?](https://www.quora.com/Why-are-system-calls-expensive-in-operating-systems)

 ### Installation

- Clone this repository: `git clone "https://github.com/dyasteek/holbertonschool-simple_shell"`
- Change directories into the repository: `cd holbertonschool-simple_shell`
- Compile: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
- Run the shell in interactive mode: `./hsh`
- Or run the shell in non-interactive mode: example `echo "Hello world!" | ./hsh`

### Files

|File|Description|
|---|---|
|[AUTHORS](https://github.com/Dyasteek/holbertonschool-simple_shell/blob/main/AUTHORS)|Contributors in this repository|
|[README.md](https://github.com/Dyasteek/holbertonschool-simple_shell/blob/main/README.md)|Information about our repository|
|[main.c](https://github.com/Dyasteek/holbertonschool-simple_shell/blob/main/main.c)|Main function and shell loop|
|[_execve.c](https://github.com/Dyasteek/holbertonschool-simple_shell/blob/main/_execve.c)|Execute builtins and commands|
|[_getenv.c](https://github.com/Dyasteek/holbertonschool-simple_shell/blob/main/_getenv.c)|Get environment variables|
|[aux.c](https://github.com/Dyasteek/holbertonschool-simple_shell/blob/main/aux.c)|Built-in functions and utilities|
|[pathstruct.c](https://github.com/Dyasteek/holbertonschool-simple_shell/blob/main/pathstruct.c)|PATH handling and command finding|
|[shell.h](https://github.com/Dyasteek/holbertonschool-simple_shell/blob/main/shell.h)|Header file with function prototypes|
|[man_1_simple_shell](https://github.com/Dyasteek/holbertonschool-simple_shell/blob/main/man_1_simple_shell)|Manual page of Simple Shell|


### Allowed functions used 

* All functions from string.h
* `access` (man 2 access)
* `chdir` (man 2 chdir)
* `close` (man 2 close)
* `closedir` (man 3 closedir)
* `execve` (man 2 execve)
* `exit` (man 3 exit)
* `_exit` (man 2 _exit)
* `fflush` (man 3 fflush)
* `fork` (man 2 fork)
* `free` (man 3 free)
* `getcwd` (man 3 getcwd)
* `getline` (man 3 getline)
* `getpid` (man 2 getpid)
* `isatty` (man 3 isatty)
* `kill` (man 2 kill)
* `malloc` (man 3 malloc)
* `open` (man 2 open)
* `opendir` (man 3 opendir)
* `perror` (man 3 perror)
* `printf` (man 3 printf)
* `fprintf` (man 3 fprintf)
* `vfprintf` (man 3 vfprintf)
* `sprintf` (man 3 sprintf)
* `putchar` (man 3 putchar)
* `read` (man 2 read)
* `readdir` (man 3 readdir)
* `signal` (man 2 signal)
* `stat` (__xstat) (man 2 stat)
* `lstat` (__lxstat) (man 2 lstat)
* `fstat` (__fxstat) (man 2 fstat)
* `strtok` (man 3 strtok)
* `wait` (man 2 wait)
* `waitpid` (man 2 waitpid)
* `wait3` (man 2 wait3)
* `wait4` (man 2 wait4)
* `write` (man 2 write)



## Authors

<li> Erick Gaiero - <a href="https://github.com/ErickGaiero">ErickGaiero</a></li>
<li> Andres del Rio - <a href="https://github.com/Dyasteek">Dyasteek</a></li>
