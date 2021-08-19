#include "header.h"

int (*builtin_func[]) (char **) = {
	&shell_cd,
	&shell_help,
	&shell_exit
};

/**
 *num_builtins - int
 *Return: number of arguments
 */
int num_builtins(void)
{
	char *builtin_str[] = { "cd", "help", "exit"};

	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 *shell_help - Builtin command: print help.
 *Return: Always returns 1, to continue executing.
 */
int shell_help(void)
{
	int i;

	printf("Richard Matovu & Stacey Nakanwagi's Simple Shell\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");

	char *builtin_str[] = { "cd", "help", "exit"};

	for (i = 0; i < num_builtins(); i++)
		printf("  %s\n", builtin_str[i]);

	printf("Use the man command for information on other programs.\n");
	return (1);
}

/**
 *execute - execute the shell program
 *@args: Null terminated list of arguments
 *Return: 1 if shell should continue running, 0 if it should terminate
 */
int execute(char **args)
{
	int i;
	char *builtin_str[] = { "cd", "help", "exit"};

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])(args));
	}

	return (launch(args));
}

/**
 * main - Shell's main function
 * @argc: int
 * @argv: char
 * Return: Always 0
 */
int main(int argc __attribute__((unused)),
	 char *argv[] __attribute__((unused)))
{
	char *line;
	char **args;
	int status;

	do {
		if (isatty(STDIN_FILENO))
		{
			write(STDIN_FILENO, "richard$ ", 13);
		}
		line = read_line();
		args = split_line(line);
		status = execute(args);
	} while (status);

	return (EXIT_SUCCESS);
}
