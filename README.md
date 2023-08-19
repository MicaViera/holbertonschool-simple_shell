# Simple Shell project

This project is a team collaboration for the end of the quarter at Holberton School.
---


## Description

The goal of this project is to create a basic command-line interpreter, also known as a Shell, that provides users with an interface to interact with the operating system. This README provides an overview of the project and how to use the Simple Shell.


## Introduction

The Simple Shell project is an implementation of a basic command-line interpreter written in C. It allows users to enter commands and execute them, providing access to various operating system services.


## Requirements of the Project:

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Your code should use the `Betty` style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to


## The tasks of the project:

*Task 0: Write a README
Write a man for your shell.
You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker.

*Task 1: Write a beautiful code that passes the Betty checks

*Task 2: Write a UNIX command line interpreter.

*Task 3: Handle command lines with arguments.

*Task 4: Handle the PATH
fork must not be called if the command doesn’t exist.

*Task 5: Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit.

*Task 6: Implement the env built-in, that prints the current environment.


## Compilation:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
Here is a list of all the necessary files in this repository.
* enveneitor.c - Function that gets the PATH, finds the executable PATH and prints the enviroment.
*  execveitor.c - Function that executes and Forks.
*  main.h - All the necessary Libraries and the Functions Prototypes.
*  tokeneitor.c - Function that tokenizes the input and returns it in a array of strings.
*  simple_shell.c - Main function of the Shell command interpreter.


## Usage Examples
- Open the terminal.

- ls Command (list): This command is used to list the files and directories in the current directory. Type and execute the following:

```bash
ls
```
You will see a list of files and directories in the current directory.

cd Command (change directory): This command is used to change the current directory. For example, if you want to enter the "Documents" directory, execute:

```bash
cd Documents
```
Now you will be in the "Documents" directory.


## Installation

To get started with the Simple Shell, follow these steps:

- Clone this repository to your local machine.
```bash
git clone https://github.com/RomiPla/holbertonschool-simple_shell.git
```
- Compile the source code using [gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh].
- Run the compiled executable.
- You should now see the shell prompt, where you can enter commands.


## Support:
For any issue, bug or assistance, you can find us on GitHub:
* [Romina Pla Acosta](https://github.com/RomiPla)
* [Noelia Micaela Viera Larrosa](https://github.com/MicaViera)
