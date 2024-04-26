/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 10:14:55 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/03/13 19:02:00 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_formats(const char *str, va_list args)
{
	int		count;

	count = 0;
	if (*str == 'c')
		count += ft_write_char(va_arg(args, int));
	else if (*str == 's')
		count += ft_write_str(va_arg(args, char *));
	else if (*str == 'd' || *str == 'i')
		count += ft_write_int(va_arg(args, int));
	else if (*str == 'p')
		count += ft_ptr_itoa(va_arg(args, unsigned long));
	else if (*str == 'x' || *str == 'X')
		count += ft_hexitoa(va_arg(args, int), *str);
	else if (*str == 'u')
		count += ft_uitoa(va_arg(args, unsigned int));
	else if (*str == '%')
		count += ft_write_char('%');
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		n;
	va_list	args;

	count = 0;
	if (str == NULL)
		return (0);
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%' && (*str + 1 != '\0'))
		{
			str++;
			n = ft_formats(str, args);
			if (n > -1)
				count = count + n;
			else
				return (-1);
		}
		else
			count += ft_write_char(*str);
		str++;
	}
	va_end(args);
	return (count);
}
