/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 17:02:10 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/11/02 14:21:15 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Compares two strings up to a specified number of characters.
Output:
1. If the strings are equal => returns 0 
2. If the first string is greater => a positive value
3. If the second string is greater => a negative value
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && n--)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("Difference between messages: %d\n", 
//	ft_strncmp("Hello.", "Hello, everyone.", 1));
// 	return (0);
// }
