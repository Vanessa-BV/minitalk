/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 16:07:07 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/10/12 16:07:07 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
used to concatenate two strings together

input:
1. s1 (first input string)
2. s2 (second input string)

output:
A pointer to a new string that contains the concatenation of s1 and s2

notes:
1. ft_strlcpy null terminates the string => hence in line 41 & 43 "strlen + 1"
to skip the null terminator. and the reason why no null terminator
was added at the end of the new string.
2. temp is created because it points to the first memory address, which
needs to be returned by the function.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	char	*temp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = (char *)ft_calloc((ft_strlen(s1)
				+ ft_strlen(s2) + 1), sizeof(char));
	if (new_str == NULL)
		return (NULL);
	temp = new_str;
	ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
	new_str += ft_strlen(s1);
	ft_strlcpy(new_str, s2, ft_strlen(s2) + 1);
	return (temp);
}

// int	main(void)
// {
// 	char const	*str1 = "Hello, ";
// 	char const	*str2 = "world.";
// 	char		*str3;

// 	str3 = ft_strjoin(str1, str2);
// 	if (str3 == NULL)
// 		printf("Allocation failed.\n");
// 	else
// 	{
// 		printf("%s\n", str3);
// 		free(str3);
// 	}
// 	return (0);
// }
