/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:43:03 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/09 19:47:55 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

intmax_t	getintarg(t_placeholder *ph, va_list ap)
{
	if (ft_strequ(ph->length, "hh"))
		return ((signed char)va_arg(ap, int));
	if (ft_strequ(ph->length, "h"))
		return ((short)va_arg(ap, int));
	if (ft_strequ(ph->length, "l") || ph->type == 'D')
		return (va_arg(ap, long));
	if (ft_strequ(ph->length, "ll"))
		return (va_arg(ap, long long));
	if (ft_strequ(ph->length, "j"))
		return (va_arg(ap, intmax_t));
	if (ft_strequ(ph->length, "z"))
		return (va_arg(ap, ssize_t));
	return (va_arg(ap, int));
}

static void	psign(t_placeholder *ph)
{
	if (ft_strcont(ph->flags, '+'))
		ft_putchar_fd('+', 1);
	else if (ft_strcont(ph->flags, ' '))
		ft_putchar_fd(' ', 1);
	else
		ph->width++;
}

static void	lsign(t_placeholder *ph)
{
	(void)ph;
	ft_putchar_fd('-', 1);
}

static void		ssign(t_placeholder *ph, char sign)
{
	(void)ph;
	if (sign == '-')
		lsign(ph);
	else
		psign(ph);
	ph->width--;
}

void		conv_d(t_placeholder *ph, va_list ap)
{
	intmax_t		nbr;
	char			sign;
	char			*str;

	nbr = getintarg(ph, ap);
	str = ft_imaxtoa_sign(nbr, &sign);
	ssign(ph, sign);
	numprec(ph, &str);
	width(ph, &str);
	ft_putstr_fd(str, 1);
	ft_strdel(&str);
}
