/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 17:01:48 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/11/02 16:30:09 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
used to set a block of memory to a specific value.

input:
1. A pointer to the starting location of the memory block to be filled.
2. The value to be inserted into each byte of the memory block.
3. The number of bytes to be filled with the specified value.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr_to_s;
	unsigned char	c_new;

	ptr_to_s = (unsigned char *)s;
	c_new = (unsigned char)c;
	while (n > 0)
	{
		*ptr_to_s = c_new;
		ptr_to_s++;
		n--;
	}
	return (s);
}

// int main(void)
// {
//     char    buffer[15];

//     printf("%s", (char *)ft_memset(buffer, 'a', 5*sizeof(char)));
//     printf("%s\n", (char *)ft_memset(buffer+5, 'b', 5*sizeof(char)));
// 	// printf("Test:\n");
// 	// printf("%s", (char *)memset(buffer, 'a', 5*sizeof(char)));
//     // printf("%s\n", (char *)memset(buffer+5, 'b', 5*sizeof(char)));
//     return (0);
// }