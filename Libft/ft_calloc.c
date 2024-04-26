/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 14:31:55 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/10/28 09:49:25 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/*
calloc is used to allocate memory for an array
and initialize the allocated memory block with zeros

Input:
- nmemb: The number of elements to be allocated.
-size: The size of each element in bytes
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// int	main(void)
// {
// 	int	*numbers;
// 	int	length;
// 	int	i;

// 	length = 0;
// 	i = 0;
// 	// numbers = calloc(length, sizeof(int));
// 	numbers = ft_calloc(length, sizeof(int));
// 	if (numbers != 0)
// 	{
// 		while (i < length)
// 		{
// 			printf("%d", numbers[i]);
// 			i++;
// 		}
// 		free(numbers);
// 	}
// 	else
// 		printf("Memory allocation failed.");
// 	return (0);
// }
