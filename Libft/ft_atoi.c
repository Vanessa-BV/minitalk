/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 12:52:26 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/10/27 15:12:50 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
atoi is to convert a string of characters
into a numerical value. It takes a string
as input and returns the corresponding
integer value

notes:
1. skips leading white space and looks for sign (+/-), if applicable
2. converts array to integer 
3. returns int with sign (-), if applicable
*/

int	ft_atoi(const char *nptr)
{
	int	number;
	int	neg_vs_pos;
	int	i;

	neg_vs_pos = 1;
	i = 0;
	number = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg_vs_pos = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + (nptr[i] - '0');
		i++;
	}
	return (number * neg_vs_pos);
}

// int	main(void)
// {
// 	const char	*str = "	-123";
// 	int			n;

// 	n = ft_atoi(str);
// 	printf("%d\n", n);
// 	// n = atoi(str);
// 	// printf("atoi test: %d\n", n);
// 	return (0);
// }
