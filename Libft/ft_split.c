/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 11:37:09 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/11/02 16:24:59 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Divides a string into smaller parts based on a given delimiter.

Output:
1. an array of strings, where each element represents a substring.
The original string is not modified.
=> a pointer to a pointer, char **, is used as the return type
because the function needs to return an array of strings,
where each element represents a substring.
2. char ** allows the function to return a dynamically
allocated array of strings. By using a pointer to a pointer, 
the function can allocate memory for each substring and
store the starting address of each substring in the array.
The NULL pointer at the end of the array marks the
end of the substrings.
*/

static size_t	ft_substr_count(char const *s, char c)
{
	size_t	count;
	size_t	index;

	count = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index] && s[index] != c)
		{
			count++;
			while (s[index] && s[index] != c)
				index++;
		}
	}
	return (count);
}

static int	ft_split_word(char **result, char const *s, char c, int substr)
{
	int	substr_s;
	int	substr_e;

	substr_s = 0;
	substr_e = 0;
	while (s[substr_e])
	{
		if (s[substr_e] == c || s[substr_e] == 0)
			substr_s = substr_e + 1;
		if (s[substr_e] != c && (s[substr_e + 1] == c || s[substr_e + 1] == 0))
		{
			result[substr] = ft_calloc((substr_e - substr_s + 2), sizeof(char));
			if (!result[substr])
			{
				while (substr--)
					free(result[substr]);
				free (result);
				return (0);
			}
			ft_strlcpy(result[substr], (s + substr_s), substr_e - substr_s + 2);
			substr++;
		}
		substr_e++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = ft_calloc((ft_substr_count(s, c) + 1), sizeof(char *));
	if (!result)
		return (NULL);
	if (!ft_split_word(result, s, c, 0))
		return (NULL);
	return (result);
}

// int	main(void)
// {
// 	char const	*string = "Hello world   and   everyone else";
// 	char		delimiter = ' ';
// 	char		**result;
// 	int			i;

// 	i = 0;
// 	result = ft_split(string, delimiter);
// 	if (result == NULL)
// 		{
// 			printf("Memory allocation failed.\n");
// 			return (1);
// 		}
// 	while (result[i] != NULL)
// 	{
// 		printf("%s\n", result[i]);
// 		free (result[i]);
// 		i++;
// 	}
// 	// result = split(string, delimiter);
// 	// while (result[i] != NULL)
// 	// {
// 	// 	printf("%s\n", result[i]);
// 	// 	free (result[i]);
// 	// 	i++;
// 	// }
// 	free (result);
// 	return (0);
// }
