/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshi <kyoshi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:32:57 by kakubo-l          #+#    #+#             */
/*   Updated: 2025/09/26 22:12:33 by kyoshi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_format_check(const char flag, va_list args)
{
	if (flag == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (flag == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (flag == 'd' || flag == 'i')
		return (ft_print_decimal(va_arg(args, int)));
	else if (flag == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (flag == 'x' || flag == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), flag));
	else if (flag == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	else if (flag == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_format_check(format[i], args);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
