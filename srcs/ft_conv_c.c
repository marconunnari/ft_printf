/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 17:43:37 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/14 19:12:26 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		cputwithwidth(t_placeholder *ph, char c)
{
	char		*fix;
	char		chr;

	if (ph->width < 1)
		return (ft_printf_putchar(c));
	ph->width--;
	fix = ft_strnew(ph->width);
	chr = ft_strcont(ph->flags, '0') && !ft_strcont(ph->flags, '-') ? '0' : ' ';
	ft_memset(fix, chr, ph->width);
	if (!ft_strcont(ph->flags, '-'))
		ft_printf_putstr(fix);
	ft_printf_putchar(c);
	if (ft_strcont(ph->flags, '-'))
		ft_printf_putstr(fix);
	ft_strdel(&fix);
}

void			conv_c(t_placeholder *ph, va_list ap)
{
	char	chr;

	if (ft_strequ(ph->length, "l"))
		return (conv_wc(ph, ap));
	chr = (char)va_arg(ap, int);
	cputwithwidth(ph, chr);
}
