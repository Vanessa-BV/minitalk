/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 12:51:57 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/11/02 14:53:16 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
extracts a portion of a string

Input: 
1. str: The original string from which the substring will be extracted.
2. start: The starting position of the substring within the original string.
3. length: The length of the substring to be extracted

Output:
1. a substring of the original string based on
the specified starting position and length - returns
pointer to the extracted substring

Notes:
1. if start > length of s => return empty string
2. if len > length of s => adjust len 
3. substr len shall not exceed len
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	substr_len;
	size_t	src_len;

	src_len = ft_strlen(s);
	substr_len = src_len - (size_t)start;
	if (!s)
		return (NULL);
	if (src_len < start)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (len > src_len)
		len = src_len - start + 1;
	if (substr_len > len)
		substr_len = len;
	sub = (char *)ft_calloc(substr_len +1, sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, (s + start), (len + 1));
	return (sub);
}

// int	main(void)
// {
// 	const char		str[] = "tripouille";
// 	unsigned int	start;
// 	size_t			len;
// 	char			*substr;

// 	start = 2;
// 	len = 4;
// 	substr = ft_substr(str, start, len);
// 	if (substr == NULL)
// 		printf("Allocation failed.\n");
// 	else
// 	{
// 		printf("%s\n", substr);
// 		free(substr);
// 	}
// 	return (0);
// }
