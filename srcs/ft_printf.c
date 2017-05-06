/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 17:39:33 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/06 17:58:49 by mnunnari         ###   ########.fr       */
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
	int		len;

	len = ft_strlen(str);
	write(fd, str, len);
	g_res += len;
}

void			do_print(const char *format, va_list ap)
{
	(void)format;
	(void)ap;
	ft_putstr_fd(format, 1);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	do_print(format, ap);
	va_end(ap);
	return (g_res);
}
