/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:46:13 by yvieira-          #+#    #+#             */
/*   Updated: 2025/02/13 21:22:08 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_int_min(int *len, int *n)
{
	if (*n == INT_MIN)
	{
		*len += write(1, "-2147483648", 11);
		return (1);
	}
	return (0);
}

int	ft_print_unsigned(unsigned int n)
{
	char	buffer[11];
	int		len;
	int		i;

	len = 0;
	i = 10;
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	buffer[10] = '\0';
	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	len += write(1, &buffer[i + 1], 10 - i);
	return (len);
}

int	ft_print_int(int n)
{
	char	buffer[12];
	int		len;
	int		i;

	len = 0;
	if (is_int_min(&len, &n))
		return (len);
	if (n == 0)
		return (write(1, "0", 1));
	if (n < 0)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	buffer[11] = '\0';
	i = 10;
	while (n)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	len += write(1, &buffer[i + 1], 10 - i);
	return (len);
}

int	process_format(const char *format, va_list args)
{
	char	c;
	int		count;

	count = 0;
	if (*format == 'c')
	{
		c = va_arg(args, int);
		count += write(1, &c, 1);
	}
	else if (*format == 's')
		count += ft_print_string(va_arg(args, const char *));
	else if (*format == 'd' || *format == 'i')
		count += ft_print_int(va_arg(args, int));
	else if (*format == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (*format == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (*format == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (*format == 'p')
		count += ft_print_pointer(va_arg(args, void *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '%')
		{
			write(1, "%", 1);
			count++;
			format += 2;
		}
		else if (*format == '%')
		{
			format++;
			count += process_format(format++, args);
		}
		else
			count += write(1, format++, 1);
	}
	va_end(args);
	return (count);
}
