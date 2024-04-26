/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 11:32:30 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/11/02 13:36:52 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
applies a given function to each character
of a string and returns a new string with the
modified character.

Input:
1.`s`: A pointer to the input string.
2. `f`: A function that takes two parameters:
the index of the character and the character itself.

Output:
1. a pointer to the modified string

applies the provided function f to each character
of the input string s and returns a new string
with the modified characters.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s);
	if (s == NULL || f == NULL)
		return (NULL);
	result = (char *)ft_calloc((len + 1), sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}

// char	uppercase(unsigned int i, char c)
// {
// 	if (i % 8 == 0)
// 		return (ft_toupper(c));
// 	else
// 		return (ft_tolower(c));
// }

// int	main(void)
// {
// 	char const	*string = "KsfhkETIpklh";
// 	char		*result = ft_strmapi(string, uppercase);
// 	if (result == NULL)
// 		printf("Allocation failed.\n");
// 	else
// 	{
// 		printf("%s\n", result);
// 		free (result);
// 	}
// 	return (0);
// }
