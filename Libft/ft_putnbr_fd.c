/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 14:37:35 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/10/17 14:37:35 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
used to print an integer to a specific file descriptor

input:
1. n: The integer to be printed.
2. fd: The file descriptor where the output will be printed.

output:
The putnbr_fd function will print the integer n to the
specified file descriptor.

notes:
1.recursion: if n>10 => e.g., 214
214/10 = 21, 21/10 = 2 => 2 remains
2. 2 < 10 => converted to ASCII value + written to fd
3. 21 % 10 = 1 => 1 is written to fd
4. 214 % 10 = 4 => 4 i written to fd
*/

void	ft_putnbr_fd(int n, int fd)
{
	char			digit;
	unsigned int	numb;

	if (n < 0)
	{
		write (fd, "-", 1);
		numb = -n;
	}
	else
		numb = n;
	if (numb < 10)
	{
		digit = numb + '0';
		write (fd, &digit, 1);
	}
	else
	{
		ft_putnbr_fd(numb / 10, fd);
		digit = numb % 10 + '0';
		write (fd, &digit, 1);
	}
}

// int	main(void)
// {
// 	int n;
// 	int fd;

// 	n = 2147483647;
// 	fd = 1;
// 	ft_putnbr_fd(n, fd);
// 	return (0);
// }