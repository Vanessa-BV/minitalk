/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_various.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 10:16:07 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/03/13 19:01:55 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_write_int(int n)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_itoa(n);
	if (str == NULL)
		return (0);
	count = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (count);
}

int	ft_write_str(char *str)
{
	if (str == NULL)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_write_char(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	else
		return (1);
}
