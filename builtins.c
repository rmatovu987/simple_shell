#include "header.h"

/**
 *shell_cd - Bultin command: change directory.
 *@args: List of args.  args[0] is "cd".  args[1] is the directory.
 *Return: Always returns 1, to continue executing.
 */
int shell_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "./shell: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("shell");
		}
	}
	return (1);
}

/**
 * shell_exit - Builtin command: exit.
 * Return: Always returns 0, to terminate execution.
 */
int shell_exit(void)
{
	return (0);
}
