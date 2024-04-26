/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 17:01:31 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/10/09 17:01:31 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
memcmp compares two blocks of memory and returns an integer
value indicating their relationship. looks for the first byte
that does not match between the two blocks and returns the
difference between the ASCII values of those bytes.

input:
1. str1 and str2 (pointers to the memory blocks you want to compare).
These memory blocks can contain any type of data, not just strings.
2. The n parameter specifies the number of bytes to compare
between the memory blocks.

1. If the value < 0 = first block < second block.
2. If value > 0 = first block > second block.
3. If the value == 0 = the two blocks are equal
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	unsigned int	i;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (string1[i] != string2[i])
			return (string1[i] - string2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	str1[] = "abcd";
// 	char	str2[] = "bcde";

// 	printf("%d\n", ft_memcmp(str1, str2, sizeof(str1)));
// 	printf("%d\n", memcmp(str1, str2, sizeof(str1)));
// 	return (0);
// }
