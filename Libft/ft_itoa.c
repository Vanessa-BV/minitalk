/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 15:48:29 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/11/02 14:11:31 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
itoa takes an integer as input and returns
a string representation of that integer.
It dynamically allocates memory for the string
and handles both positive and negative integers.

ft_count_digit:
static int is used because it will preserve the value of int.
Otherwise, it would be set to 0 every time and the
function would run again.

notes:
1. number = long int to handle a larger range of int values.
allows to store larger numbers without overflow - common practice to 
use long int in integer conversions.
2.example: 214 => 214%10=4 
3.first iteration converts int 4 to ASCII value 4. value of '0' is 48
48 + 4 = 52 (ASCII) = 4, thus str = 4, numb (214) / 10 = 21
4. second iteration, 21%10=1, converts 1 to ASCII, thus str = 14,
num 21/10 = 2,
5. third iteration 2%10=2, 2 converted to ASCCI, str = 214
*/

static int	ft_count_digit(long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			index;
	long int	numb;
	int			int_size;

	numb = n;
	int_size = ft_count_digit(n);
	str = (char *)ft_calloc((int_size + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	index = int_size - 1;
	if (numb < 0)
	{
		str[0] = '-';
		numb *= -1;
	}
	if (numb == 0)
		str[0] = '0';
	while (numb > 0)
	{
		str[index--] = (numb % 10) + '0';
		numb /= 10;
	}
	return (str);
}

// int	main(void)
// {
// 	int		n;
// 	char	*result;

// 	n = 983;
// 	result = ft_itoa(n);
// 	printf("%s\n", result);
// 	free(result);
// 	// result = itoa(n);
// 	// printf("%s\n", n);
// 	// free(result);
// 	return (0);
// }
