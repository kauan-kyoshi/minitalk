/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakubo-l <kakubo-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:41:05 by kakubo-l          #+#    #+#             */
/*   Updated: 2025/09/29 15:26:22 by kakubo-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putptr_len(unsigned long long n)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		len += ft_putptr_len(n / 16);
	len += ft_print_char(base[n % 16]);
	return (len);
}

int	ft_print_pointer(void *ptr)
{
	unsigned long long	p;
	int					len;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	p = (unsigned long long)ptr;
	len = 0;
	len += write(1, "0x", 2);
	len += ft_putptr_len(p);
	return (len);
}
