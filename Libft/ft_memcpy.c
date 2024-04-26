/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 17:01:37 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/10/09 17:01:37 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
used to copy a block of memory from one location to another.

input:
1. The destination pointer
2. The source pointer
3. The number of bytes to copy.

notes:
1. returning "dest" => Returning dest without copying data is
crucial to prevent memory access violations when either or
both pointers are NULL, which could otherwise lead to
segmentation faults or other errors.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	unsigned int	i;

	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (destination == NULL && source == NULL)
		return (dest);
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}

// int main(void)
// {
//     unsigned char source[] = {10, 20, 30, 40, 50};
//     unsigned char destination[5] = {0};
//     size_t i;

// 	i = 0;
//     ft_memcpy(destination, source, sizeof(source));
//     while (i < sizeof(destination))
//     {
//         printf("%u ", destination[i]);
//         i++;
//     }
// printf("\n");
// i = 0;
// memcpy(destination, source, sizeof(source));
// printf("Test:\n");
// while (i < sizeof(destination))
// {
//     printf("%u ", destination[i]);
//     i++;
// }
// return (0);
// }