/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 09:31:49 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/10/31 15:48:25 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
appends the NUL-terminated string src to the end of dst.
It will append at most size strlen(dst) - 1 bytes,
NUL-terminating the result.

input:
1. dst: The destination string where
the source string will be appended
2. src: The source string that will be
appended to the destination string
3. size: The size of the destination buffer,
incl. the null-terminator. Important to provide
the correct size to avoid buffer overflow.

output:
1. the length of the concatenated string, if it fits
within the dest buffer. thus original dst + src length
2. if it does not fit in dest buffer => returns returns length
of src + size of dest buffer
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	avail_space;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	avail_space = size - dst_len - 1;
	if (dst_len >= size)
		return (size + src_len);
	if (src_len < avail_space)
		ft_memcpy(dst + dst_len, src, src_len + 1);
	else
	{
		ft_memcpy(dst + dst_len, src, avail_space);
		dst[dst_len + avail_space] = '\0';
	}
	return (dst_len + src_len);
}

// int	main(void)
// {
// 	char		dest[] = "Hello ";
// 	const char	*src = "world";
// 	size_t		result;

// 	result = ft_strlcat(dest, src, sizeof(dest));
// 	printf("%s\n", dest);
// 	printf("%zu\n", result);
// 	// char		desti[] = "Hello, ";
// 	// result = strlcat(desti, src, sizeof(dest));
// 	// printf("Test: %s\n", dest);
// 	// printf("Test: %zu\n", result);
// 	return (0);
// }
