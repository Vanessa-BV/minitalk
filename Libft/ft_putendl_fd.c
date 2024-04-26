/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 14:51:15 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/10/17 14:51:15 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
takes a string s and writes it followed by a newline
character to the specified file descriptor fd.

input:
1.s: A pointer to a null-terminated string to be written.
2.fd: The file descriptor where the string will be written.

output:
The string s, followed by a newline character, is written
to the file descriptor fd.
*/

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	len;

	len = ft_strlen(s);
	write(fd, s, len);
	write (fd, "\n", 1);
}

// int	main(void)
// {
// 	char	*str = "Hello";
// 	int		fd;

// 	fd = 1;
// 	ft_putendl_fd(str, fd);
// 	return (0);
// }