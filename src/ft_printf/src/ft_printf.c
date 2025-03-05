/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weast <weast@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:14:02 by weast             #+#    #+#             */
/*   Updated: 2025/03/05 15:54:30 by weast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format_type(char specifier, va_list args)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len = ft_putchar_fd((char)(va_arg(args, int)), 0);
	else if (specifier == 's')
		len = ft_putstr_fd(va_arg(args, char *), 0);
	else if (specifier == 'p')
		len = ft_putpointer(va_arg(args, void *), "0123456789abcdef");
	else if (specifier == 'i' || specifier == 'd')
		len = ft_putint(va_arg(args, int), "0123456789");
	else if (specifier == 'u')
		len = ft_putuint(va_arg(args, unsigned int), "0123456789");
	else if (specifier == 'x')
		len = ft_putuint(va_arg(args, unsigned int), "0123456789abcdef");
	else if (specifier == 'X')
		len = ft_putuint(va_arg(args, unsigned int), "0123456789ABCDEF");
	else
		len = ft_putchar_fd('%', 0);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	total_len;

	if (!str)
		return (-1);
	i = 0;
	total_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			total_len += parse_format_type(str[i + 1], args);
			i += 2;
		}
		else
			total_len += ft_putchar_fd(str[i++], 0);
	}
	va_end(args);
	return (total_len);
}
