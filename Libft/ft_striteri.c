/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 12:32:04 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/11/02 16:43:25 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
applies a given function to each character
of a string, along with its index.

input:
1. s: A pointer to the string you want to modify.
2. f: A function that takes an unsigned integer
(representing the index) and a character pointer as arguments.
*/

void	ft_striteri(char *s, void (*f) (unsigned int, char*))
{
	int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]),
		i++;
	}
}

// void	print_index_and_char(unsigned int index, char *character)
// {
// 	printf("Index %u: %c\n", index, *character);
// }

// int	main(void)
// {
// 	char	*str = "Hello!";
// 	ft_striteri(str, print_index_and_char);
// 	return (0);
// }