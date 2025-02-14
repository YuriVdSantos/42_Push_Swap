/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:15:41 by yvieira-          #+#    #+#             */
/*   Updated: 2025/02/13 21:22:25 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	process_hex_conversion(unsigned int n, char *base)
{
	char	buffer[9];
	int		len;
	int		i;

	len = 0;
	i = 8;
	buffer[8] = '\0';
	if (n == 0)
	{
		buffer[7] = '0';
		len += write(1, &buffer[7], 1);
	}
	else
	{
		while (n)
		{
			buffer[i--] = base[n % 16];
			n /= 16;
		}
		len += write(1, &buffer[i + 1], 8 - i);
	}
	return (len);
}

int	ft_print_hex(unsigned int n, int uppercase)
{
	char	*base;
	int		len;

	len = 0;
	if (uppercase)
	{
		base = "0123456789ABCDEF";
	}
	else
	{
		base = "0123456789abcdef";
	}
	len += process_hex_conversion(n, base);
	return (len);
}

int	ft_print_pointer(void *ptr)
{
	unsigned long	addr;
	char			buffer[18];
	int				len;
	char			*base;
	int				i;

	len = 0;
	i = 17;
	base = "0123456789abcdef";
	buffer[17] = '\0';
	addr = (unsigned long)ptr;
	if (addr == 0)
	{
		return (write(1, "(nil)", 5));
	}
	while (addr)
	{
		buffer[i--] = base[addr % 16];
		addr /= 16;
	}
	len += write(1, "0x", 2);
	len += write(1, &buffer[i + 1], 17 - i);
	return (len);
}

int	ft_print_string(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		s = "(null)";
	while (s[len])
		write(1, &s[len++], 1);
	return (len);
}
