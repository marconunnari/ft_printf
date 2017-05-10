/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 17:43:37 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/10 16:37:57 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		cputwithwidth(t_placeholder *ph, char c)
{
	char		*fix;
	char		chr;

	IFRETURN(ph->width < 1, ft_putchar_fd(c, 1));
	ph->width--;
	fix = ft_strnew(ph->width);
	chr = ft_strcont(ph->flags, '0') && !ft_strcont(ph->flags, '-') ? '0' : ' ';
	ft_memset(fix, chr, ph->width);
	if (!ft_strcont(ph->flags, '-'))
		ft_putstr_fd(fix, 1);
	ft_putchar_fd(c, 1);
	if (ft_strcont(ph->flags, '-'))
		ft_putstr_fd(fix, 1);
	ft_strdel(&fix);
}

void		conv_c(t_placeholder *ph, va_list ap)
{
	char	chr;

	IFRETURN(ft_strequ(ph->length, "l"), conv_wc(ph, ap))
	chr = (char)va_arg(ap, int);
	cputwithwidth(ph, chr);
}
