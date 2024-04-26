/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 17:02:17 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/11/02 16:39:29 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
searches for a substring within a given string.
Returns a pointer to the first occurrence of the substring
or NULL if the substring is not found.

Input:
1. `big`: string in which the search is performed.
It is the larger string that you want to search within.
2. `little`: substring that you want to search for
within the `big`. It is the word or sequence of
characters that you are looking for.
3. `len`: This is the maximum number of characters to search.
Allows you to specify the length of the `big` 
string to limit the search range.
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&(big[i]));
			else if (little[j] != big[i + j] || big[i + j] == '\0')
				break ;
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*str1 = "Hello, world.";
// 	const char	*str2 = "world";
// 	char		*result = ft_strnstr(str1, str2, strlen(str1));

// 	if (result != NULL)
// 		printf("Substring found at index: %ld\n", result - str1);
// 	else
// 		printf("Substring not found.\n");
// 	return (0);
// }
