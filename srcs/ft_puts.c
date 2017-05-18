/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 18:32:00 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/07 18:04:45 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		g_res;

void			ft_printf_putchar(char c)
{
	write(1, &c, 1);
	g_res++;
}

void			ft_printf_putstr(const char *str)
{
	while (*str)
		ft_printf_putchar(*str++);
}

void			ft_printf_putwchar(wchar_t wchr)
{
	char	*str;

	str = wchartostr(wchr);
	ft_printf_putstr(str);
	ft_strdel(&str);
}

void			ft_printf_putwstr(const wchar_t *wstr)
{
	while (*wstr)
		ft_printf_putstr(wchartostr(*wstr++));
}
