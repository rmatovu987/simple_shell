#ifndef HEADER_H
#define HEADER_H

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define READLINE_BUFSIZE 1024
#define TOKEN_BUFSIZE 64
#define TOKEN_DELIMETER " \t\r\n\a"

int _putchar(char c);

/*Initializer*/
char *read_line(void);
char **split_line(char *line);
int launch(char **args);

/*builtin*/
int shell_cd(char **arg);
int shell_help();
int shell_exit();
int num_builtins(void);

#endif
