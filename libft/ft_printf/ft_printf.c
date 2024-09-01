/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:02:41 by htran-th          #+#    #+#             */
/*   Updated: 2024/08/27 18:18:40 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_check_format(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putaddress(va_arg(args, unsigned long long int)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr((va_arg(args, unsigned int)), 10));
	else if (c == 'x')
		return (ft_putunbr((va_arg(args, unsigned int)), 16));
	else if (c == 'X')
		return (ft_putxnbr_uppercase((va_arg(args, unsigned int)), 16));
	else if (c == '%')
		return (ft_putchar(c));
	else if (c == '\0')
		return (0);
	else
		return (ft_putchar(c));
}

static int	ft_printf_helper(const char *format, va_list args, int temp)
{
	int	count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			temp = ft_check_format(args, *(++format));
			if (temp == -1)
				return (-1);
			count += temp;
		}
		else
		{
			if (ft_putchar(*format) == -1)
				return (-1);
			count++;
		}
		if (*format != '\0')
			format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		temp;
	va_list	args;

	va_start (args, format);
	count = 0;
	temp = 0;
	count = ft_printf_helper(format, args, temp);
	va_end(args);
	return (count);
}
