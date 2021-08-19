# Simple Shell
- - -
### Description
A simple UNIX command interpreter that replicates functionalities of the simple shell (sh). Additional functions are also included. This program was written entirely in C.

### Installation
Clone this repository into local working directory. For best results, files should be compiled with 
```sh
gcc -Wall -Werror -Wextra -pedantic *.c
```

### Usage
After compilation, the resulting program can run stand-alone, either in interactive or non-interactive mode.

#### Interactive Mode
In interactive mode, simply run the program and wait for the prompt to appear. From there, type commands freely, exiting with either the "exit" command or ctrl-D.

#### Non-Interactive Mode
In non-interactive mode, echo desired command and pipe it into the program as following:
```sh
echo "ls" | ./shell
```
In non-interactive mode, the program will exit after finishing desired command(s).

#### Included Built-Ins
The shell has support for the following built-in commands:

Command | Definition
--------|---------------
exit [n] | Exit the shell, with an optional exit status, n.
env      | Print the environment.
setenv [var] [value] | Set an environment variable and value. If the variable exists, the value will be updated.
unsetenv [var] | Remove an environment variable.
cd [dir] | Change the directory.

The following built-in commands may be supported in future versions:

Command | Definition
--------|---------------
alias   | Set an Alias.
history | View the history of the shell.


#### Outside Programs
Simple shell can run outside programs by typing the absolute paths (/bin/ls) or the executable name (ls), If directory is included in the PATH.

### Examples


### Credits
All code written by [Richard Matovu](https://github.com/rmatovu987) and [Stacey Nakanwagi]().

