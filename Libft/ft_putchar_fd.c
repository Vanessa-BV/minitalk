/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 12:42:33 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/10/17 12:42:33 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
used to write a single character to a specified file descriptor.

input:
1. A character `c` and an integer file descriptor `fd`.

output:
1.Write the character `c` to the file descriptor `fd`.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	char	c;
// 	int		fd;

// 	c = 'A';
// 	fd = 1;
// 	ft_putchar_fd(c, fd);   
// 	return (0);
// }