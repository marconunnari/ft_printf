/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 18:32:00 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/06 18:40:21 by mnunnari         ###   ########.fr       */
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

void			ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
}

void			ft_putstr(const char *str)
{
	ft_putstr_fd(str, 1);
}
