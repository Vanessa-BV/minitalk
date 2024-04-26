/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 17:00:12 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/10/09 17:00:12 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
copy a string from one location to another,
while ensuring that the destination buffer
has enough space to accommodate the entire string

input:
1. dest: a pointer to the destination buffer
where the string will be copied to
2. src: a pointer to the source string that
will be copied.
3. size: the size of the destination buffer.

output:
1. returns the number of characters that were
copied, excluding the null terminator.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (size > 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
			size--;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

// int	main(void)
// {
// 	const char	*source = "hej";
// 	char		destination[20];
// 	size_t		size;
// 	size_t		copied_length;

// 	size = sizeof(destination);
// 	copied_length = ft_strlcpy(destination, source, size);
// 	printf("%zu\n", copied_length);
// 	printf("%s\n", destination);
// 	return (0);
// }
