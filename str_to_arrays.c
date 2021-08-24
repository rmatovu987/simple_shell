#include "shell.h"

/**
 * token_num - number of words on a string
 * @str: string to split
 *
 * Return: number of words
 */
unsigned int token_num(char *str)
{
	char *token;
	char sep[] = " \n\t";
	unsigned int i = 0;

	token = strtok(str, sep);
	while (token)
	{
		token = strtok(NULL, sep);
		i++;
	}

	return (i);
}

/**
 * split_token - split a string on diferent arrays
 * @str: String to split
 * @splt_str: pointer with the memory allocated fo the strs
 * @n: number of words to split
 *
 * Return: Address of the sub-strings
 */
char **split_token(char **splt_str, char *str, unsigned int n)
{
	char *token;
	char sep[] = " \n\t";
	unsigned int j = 0;

	token = strtok(str, sep);
	while (j < n)
	{
		splt_str[j] = _strdup(token);
		if (splt_str[j] == '\0')
		{
			while (j > 0)
			{
				free(splt_str[j]);
				j--;
			}
			free(splt_str[0]);
			free(splt_str);
			free(str);
			msgerr("Failed to allocate memmory to array", 1);
		}
		token = strtok(NULL, sep);
		j++;
	}
	splt_str[j] = '\0';

	return (splt_str);
}

/**
 * str_to_arrays - Split the strings to sub-strings
 * @buffer_size: String to Split
 *
 * Return: (Double pointer)Address to sub-strings
 */
char **str_to_arrays(char *buffer_size)
{
	char *aux_len, *aux_split;
	char **split_str;
	unsigned int i;

	aux_len = strdup(buffer_size);
	if (aux_len == '\0')
	{
		msgerr("Failed to allocate memory", 1);
	}
	aux_split = strdup(buffer_size);
	if (aux_split == '\0')
	{
		free(aux_len);
		msgerr("Failed to allocate memory", 1);
	}
	i = token_num(aux_len);
	aux_len = '\0';
	free(aux_len);
	split_str = malloc((i * sizeof(char *)) + 1);
	if (split_str == '\0')
	{
		free(aux_split);
		msgerr("Failed to allocate memmory", 1);
	}
	split_str = split_token(split_str, aux_split, i);
	aux_split = '\0';
	free(aux_split);
	return (split_str);
}
