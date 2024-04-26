/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 17:01:24 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/10/31 14:35:50 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
memchr searches for a specific character in a given memory
block.

input:
1. A pointer to the memory block to search in.
2. The character to search for.
3. The number of bytes to search.

output:
a pointer to the first occurrence of the character,
or NULL if the character is not found

notes:
1. unsigned char *haystack => Using unsigned char for
haystack allows you to treat each element of the memory
block as a single byte or character, making it suitable
for searching through memory at the byte level. Then
casted to void * to provide a generic pointer for various 
data types when returning the result => ensures versatility
(i.e. various data types) and compatibility with
different memory representations.
2. unsigned char needle = used to store characters
and small integers within the range of 0 to 255. 
because c is an integer, but the memory block is
treated as an array of unsigned char, so the character
to find should also be treated as an unsigned char
to ensure correct comparisons.
3. if match is found => i is added to haystack to
point to the exact location of the memory block
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*haystack;
	unsigned char	needle;
	size_t			i;

	haystack = (unsigned char *)s;
	needle = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (haystack[i] == needle)
			return ((void *)haystack + i);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[] = "Hello, world";
// 	char	to_find = 'w';
// 	char	*result = ft_memchr(str, to_find, strlen(str));
// 	// char	*result = memchr(str, to_find, strlen(str));

// 	if (result != NULL)
// 	{
// 		printf("The character is found in position %ld\n", result - str);
// 	}
// 	else
// 	{
// 		printf("The character was not found\n");
// 	}
// 	return (0);
// }
