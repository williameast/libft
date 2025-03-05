/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weast <weast@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:03:56 by weast             #+#    #+#             */
/*   Updated: 2025/03/05 14:47:46 by weast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putuint(unsigned int num, char *set);
int		ft_putpointer(void *num, char *set);
int		ft_putint(int num, char *set);
int		parse_format_type(char specifier, va_list args);
int		ft_printf(const char *str, ...);

#endif
