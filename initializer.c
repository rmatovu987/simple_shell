#include "header.h"

/**
 *read_line - function to read the entered arguements
 *Return: nothing
 */
char *read_line(void)
{
	 int bufsize = READLINE_BUFSIZE;
	 int position = 0;
	 char *buffer = malloc(sizeof(char) * bufsize);
	 int c;

	 if (!buffer) {
		 fprintf(stderr, "./shell: Allocation error\n");
		 exit(EXIT_FAILURE);
	 }

	 while (1) {
		 /*Read a character*/
		 c = getchar();

		 /*If we hit EOF, replace it with a null character and return.*/
		 if (c == EOF || c == '\n') {
			 buffer[position] = '\0';
			 return (buffer);
		 } else
		 {
			 buffer[position] = c;
		 }
		 position++;

		 /*If we have exceeded the buffer, reallocate.*/
		 if (position >= bufsize) {
			 bufsize += READLINE_BUFSIZE;
			 buffer = realloc(buffer, bufsize);
			 if (!buffer) {
				 fprintf(stderr, "./shell: Allocation error\n");
				 exit(EXIT_FAILURE);
			 }
		 }
	 }
}

/**
 *split_line - Splits the line into tokens
 *line: the line
 *Return: Null terminated array of tokens
 */
char **split_line(char *line)
{
	int bufsize = TOKEN_BUFSIZE, i = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token, **tokens_backup;

	if (!tokens)
	{
		fprintf(stderr, "./shell: Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOKEN_DELIMETER);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += TOKEN_BUFSIZE;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens)
			{
				free(tokens_backup);
				fprintf(stderr, "./shell: Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, TOKEN_DELIMETER);
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 *launch - lauch the program
 *@args: Null terminated list of arguments
 *Return: Always 1
 */
int launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if(pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("shell");
		}
		exit(EXIT_FAILURE);
	} else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		} while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}