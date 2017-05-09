/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_uox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:04:11 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/09 20:19:20 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

uintmax_t	getuintarg(t_placeholder *ph, va_list ap)
{
	if (ft_strequ(ph->length, "l") || ph->type == 'U'
			|| ph->type == 'O')
		return (va_arg(ap, unsigned long));
	if (ft_strequ(ph->length, "hh"))
		return ((unsigned char)va_arg(ap, int));
	if (ft_strequ(ph->length, "h"))
		return ((unsigned short)va_arg(ap, int));
	if (ft_strequ(ph->length, "ll"))
		return (va_arg(ap, unsigned long long));
	if (ft_strequ(ph->length, "j") || ph->type == 'p')
		return (va_arg(ap, uintmax_t));
	if (ft_strequ(ph->length, "z"))
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned int));
}

static void			flag(t_placeholder *ph, int upper)
{
	IFRETURNVOID(!(ft_strcont(ph->flags, '#') || ph->type == 'p'));
	if (ph->type == 'o')
	{
		ft_putstr_fd("0", 1);
		ph->width--;
	}
	else
	{
		upper ? ft_putstr_fd("0X", 1) : ft_putstr_fd("0x", 1);
		ph->width -= 2;
	}
}

void				conv_x(t_placeholder *ph, va_list ap)
{
	uintmax_t		u;
	char		*str;

	u = getuintarg(ph, ap);
	str = ft_uimaxtoa_base(u, 16);
	flag(ph, ft_isupper(ph->type));
	width(ph, &str);
	if (ft_isupper(ph->type))
		ft_strtoupper(str);
	ft_putstr_fd(str, 1);
	ft_strdel(&str);
}

void			conv_o(t_placeholder *ph, va_list ap)
{
	uintmax_t		u;
	char		*str;

	u = getuintarg(ph, ap);
	str = ft_uimaxtoa_base(u, 8);
	flag(ph, 0);
	width(ph, &str);
	ft_putstr_fd(str, 1);
	ft_strdel(&str);
}

void			conv_u(t_placeholder *ph, va_list ap)
{
	uintmax_t		u;
	char			*str;

	u = getuintarg(ph, ap);
	str = ft_uimaxtoa_base(u, 10);
	width(ph, &str);
	ft_putstr_fd(str, 1);
	ft_strdel(&str);
}
