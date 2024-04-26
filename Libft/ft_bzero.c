/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 14:32:05 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/10/09 14:32:05 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
bzero sets a block of memory to zero.
 Before bzero, the bytes in the buffer
 contain unknown data. After bzero, all
 bytes are set to zero
 
 input:
- a pointer s to the memory block that needs to be set to zero
- the size n of the memory block
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// int	main(void)
// {
// 	char	buffer[] = "Hello, everyone";

// 	// bzero(buffer, strlen(buffer));
// 	// printf("Bzero test: %s", buffer);
// 	printf("%s\n", buffer);
// 	ft_bzero(buffer, strlen(buffer)); 
// 	printf("%s\n", buffer);
// 	return (0);
// }
