/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_hexa.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 10:15:32 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/03/13 19:01:48 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexnb_len(unsigned long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_hexitoa(unsigned int n, const char c)
{
	char			*str;
	unsigned int	hex_len;
	char			*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (n == 0)
		return (ft_write_char('0'));
	hex_len = ft_hexnb_len(n);
	str = (char *)ft_calloc((hex_len + 1), sizeof(char));
	if (str == NULL)
		return (-1);
	while (n > 0)
	{
		str[--hex_len] = base[n % 16];
		n = n / 16;
	}
	hex_len = ft_write_str(str);
	free(str);
	return (hex_len);
}

int	ft_ptr_itoa(unsigned long n)
{
	char			*str;
	unsigned long	ptr_len;
	const char		*base;

	base = "0123456789abcdef";
	if (n == 0)
		return (ft_write_str("(nil)"));
	else
	{
		ptr_len = ft_hexnb_len(n);
		str = (char *)ft_calloc((ptr_len + 1), sizeof(char));
		if (str == NULL)
			return (-1);
		while (n > 0)
		{
			str[--ptr_len] = base[n % 16];
			n = n / 16;
		}
		ft_write_str("0x");
		ptr_len = (ft_write_str(str) + 2);
		free(str);
		return (ptr_len);
	}
}
