/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 14:25:38 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/10/17 14:25:38 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
outputs a string to a specific file descriptor.

input:
A string s that you want to output.

output:
The string s is written to the file descriptor fd.
*/

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		write (fd, s, 1);
		s++;
	}
}

// int	main(void)
// {
// 	char	*string = "Hello";
// 	int		fd;

// 	fd = 1;
// 	ft_putstr_fd(string, fd);
// 	return (0);
// }