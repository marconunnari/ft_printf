/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:43:03 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/14 19:13:27 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

intmax_t		getintarg(t_placeholder *ph, va_list ap)
{
	if (ph->type == 'D')
		return (va_arg(ap, long));
	if (ft_strchr(ph->length, 'j'))
		return (va_arg(ap, intmax_t));
	if (ft_strchr(ph->length, 'z'))
		return (va_arg(ap, ssize_t));
	if (ft_strstr(ph->length, "ll"))
		return (va_arg(ap, long long));
	if (ft_strchr(ph->length, 'l'))
		return (va_arg(ap, long));
	if (ft_strstr(ph->length, "hh"))
		return ((signed char)va_arg(ap, int));
	if (ft_strchr(ph->length, 'h'))
		return ((short)va_arg(ap, int));
	return (va_arg(ap, int));
}

static void		widthsign(t_placeholder *ph, char sign)
{
	if (sign == '-')
		ph->width--;
	else
	{
		if (ft_strcont(ph->flags, '+'))
			ph->width--;
		else if (ft_strcont(ph->flags, ' '))
			ph->width--;
	}
}

static void		ssign(t_placeholder *ph, char sign, char **str)
{
	if (sign == '-')
		*str = ft_strprepend('-', *str);
	else
	{
		if (ft_strcont(ph->flags, '+'))
			*str = ft_strprepend('+', *str);
		else if (ft_strcont(ph->flags, ' '))
			*str = ft_strprepend(' ', *str);
	}
}

void			conv_d(t_placeholder *ph, va_list ap)
{
	intmax_t		nbr;
	char			sign;
	char			*str;

	nbr = getintarg(ph, ap);
	str = ft_imaxtoa_sign(nbr, &sign);
	if (ft_strcont(ph->flags, '0'))
	{
		widthsign(ph, sign);
		numprec(ph, &str, nbr == 0);
		width(ph, &str);
		ssign(ph, sign, &str);
	}
	else
	{
		numprec(ph, &str, nbr == 0);
		ssign(ph, sign, &str);
		width(ph, &str);
	}
	ft_printf_putstr(str);
	ft_strdel(&str);
}
