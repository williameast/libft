/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: William <weast@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:32:51 by William           #+#    #+#             */
/*   Updated: 2025/03/05 16:03:09 by weast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
		return (ft_putstr("(null)"));
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

int	ft_putuint(unsigned int num, char *set)
{
	int				len;
	unsigned int	base;

	base = ft_strlen(set);
	len = 0;
	if (num >= base)
		len += ft_putuint(num / base, set);
	ft_putchar_fd(set[num % base], 0);
	len++;
	return (len);
}

int	ft_putulong(unsigned long num, char *set)
{
	int				len;
	unsigned long	base;

	base = ft_strlen(set);
	len = 0;
	if (num >= base)
		len += ft_putulong(num / base, set);
	len += ft_putchar_fd(set[num % base], 0);
	return (len);
}

int	ft_putpointer(void *num, char *set)
{
	int				len;
	unsigned long	base;
	unsigned long	ptr;

	ptr = (unsigned long)num;
	base = ft_strlen(set);
	if (!num)
		return (ft_putstr("(nil)"));
	len = ft_putstr("0x");
	if (ptr >= base)
		len += ft_putulong(ptr / base, set);
	ft_putchar_fd(set[ptr % base], 0);
	len++;
	return (len);
}

int	ft_putint(int num, char *set)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		len += ft_putchar_fd('-', 0);
		len += ft_putuint((unsigned long)(-num), set);
	}
	else
		len += ft_putuint(num, set);
	return (len);
}
