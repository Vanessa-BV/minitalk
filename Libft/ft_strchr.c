/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 17:01:54 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/10/31 14:39:12 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
used to search for a specific character in a given string.

input:
1. The string in which you want to search for the character.
2. The character you want to find.

The function then searches the string for the first
occurrence of that character. If it finds the character,
it returns a pointer (a memory address) to the location
of that character in the string.
If it does not find the character, it returns a
special value called NULL (=the character is not present)

notes:
1. final "if (*s == (unsigned char)c)" looks if c is
the null terminator and would return that if applicable
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

// int	main(void)
// {
// 	printf("The first occurrence is: %s\n", ft_strchr("Hello, world", 'w'));
// 	printf("The first occurrence is: %s\n", strchr("Hello, world", 'w'));
// 	return(0);
// }