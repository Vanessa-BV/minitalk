/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 12:41:21 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/10/31 15:36:54 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
creates a copy of a string.

input:
str - The string to be duplicated.

output:
a pointer to a newly allocated memory block containing
a copy of the input string
*/

char	*ft_strdup(const char *str)
{
	char	*duplicate;
	int		length;

	length = 0;
	while (str[length] != '\0')
		length++;
	duplicate = (char *)ft_calloc((length + 1), sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	ft_strlcpy(duplicate, str, length + 1);
	return (duplicate);
}

// int	main(void)
// {
// 	const char	*original = "Hello, world";
// 	char		*duplicate;

// 	duplicate = ft_strdup(original);
// 	printf("%s\n", original);
// 	printf("%s\n", duplicate);
// 	duplicate = strdup(original);
// 	printf("Test: %s\n", original);
// 	printf("Test: %s\n", duplicate);
// 	return (0);
// }
