![image](https://linuxize.com/post/wall-command-in-linux/featured_hu9d1cdb8ca98d0b49a857dfbca4f1a9b2_18166_768x0_resize_q75_lanczos.jpg)
<h1>Simple Shell</h1>
Release date Aug 4, 2023

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
    * Flowchart
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
* 4. Handle the PATH but fork must not be called if the command doesn’t exist.
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
|[_execve.c](https://github.com/Dyasteek/holbertonschool-simple_shell/blob/main/_execve.c )|Execute builtins and commands|
|[_getenv.c](https://github.com/Dyasteek/holbertonschool-simple_shell/blob/main/_getenv.c)|Prints enviroment to stndard output|
|[prompt.c](https://github.com/Dyasteek/holbertonschool-simple_shell/blob/main/prompt.c)|Gets input and get variable PATH||
|[shell.c](https://github.com/Dyasteek/holbertonschool-simple_shell/blob/main/shell.c)|Main arguments functions|
|[man_1_simple_shell](https://github.com/Dyasteek/holbertonschool-simple_shell/blob/main/man_1_simple_shell)|Manual page our of Simple Shell|
|[shell.h](https://github.com/Dyasteek/holbertonschool-simple_shell/blob/main/shell.h)|Prototypes functions and headers|


### Allowed functions used 

* `execve` (man 2 execve)
* `exit` (man 3 exit)
* `fork` (man 2 fork)
* `free` (man 3 free)
* `getline` (man 3 getline)
* `malloc` (man 3 malloc)
* `perror`(man 3 perror)
* `stat` (__ xstat) (man 2 stat)
* `strtok` (man 3 strtok)
* `wait` (man 2 wait)
* `fprintf` (man 3 fprintf)

## Flowchart

![image](src/simple_shell_behavior.svg)

## Authors

<li> Aaron Gonzalez - <a href="https://github.com/AaronEGH16">AaronEGH16</a></li>
<li> Andres del Rio - <a href="https://github.com/Dyasteek">Dyasteek</a></li>
