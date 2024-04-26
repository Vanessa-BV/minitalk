/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 17:01:43 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/11/02 16:32:54 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
copies a specified number of bytes from one memory location to
another, even if the memory regions overlap.

input:
1. The destination memory location
2. The source memory location
3. The number of bytes to be copied

dest >/< src = dest is after/before the src memory
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destination;
	char	*source;
	size_t	i;

	destination = (char *)dest;
	source = (char *)src;
	i = 0;
	if (destination < source)
		ft_memcpy(destination, source, n);
	else if (destination > source)
	{
		i = n;
		while (i > 0)
		{
			destination[i - 1] = source[i - 1];
			i--;
		}
	}
	return (destination);
}

// int	main(void)
// {
// 	char	source[] = "Hello, world";
// 	char	destination[20];

// 	ft_memmove(destination, source, strlen(source) + 1);
// 	printf("%s\n", destination);
// 	memmove(destination, source, strlen(source) + 1);
// 	printf("Test: %s\n", destination);
// 	return (0);
// }
