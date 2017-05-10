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

void			ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	g_res++;
}

void			ft_putstr_fd(const char *str, int fd)
{
	while (*str)
		ft_putchar_fd(*str++, fd);
}

void			ft_putwchar_fd(wchar_t wchr, int fd)
{
	char	*str;

	str = wchartostr(wchr);
	ft_putstr_fd(str, fd);
	ft_strdel(&str);
}

void			ft_putwstr_fd(const wchar_t *wstr, int fd)
{
	while (*wstr)
		ft_putstr_fd(wchartostr(*wstr++), fd);
}
