/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 17:02:22 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/11/02 14:27:42 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
used to search for a specific character in a given string.
looks for the last occurrence of that character in the string

Input:
1. The string in which you want to search for the character.
2. The character you want to find.

Output:
1. If character is found => a pointer (a memory address)
to the location of that character in the string.
2. If not found => returns a special value called NULL,
indicating that the character is not present in the string.
*/

char	*ft_strrchr(const char *s, int c)
{
	int	length;

	length = ft_strlen(s);
	while (length >= 0)
	{
		if (s[length] == (char) c)
			return ((char *)s + length);
		length--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	printf("The last occurrence is: %s\n", ft_strrchr("Hello, world!", 'l'));
// 	return (0);
// }