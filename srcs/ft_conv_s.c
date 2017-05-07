/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:42:54 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/07 16:26:27 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		precision(t_placeholder *ph, char **str)
{
	*str = ft_strdup(*str);
	IFRETURNVOID(ph->precision == -1);
	*str = ft_strsub(*str, 0, ph->precision);
}

void		width(t_placeholder *ph, char **str)
{
	char		*fix;
	char		chr;
	int		strlen;

	strlen = ft_strlen(*str);
	IFRETURNVOID(ph->width < strlen);
	fix = ft_strnew(ph->width - strlen);
	chr = ft_strcont(ph->flags, '0') ? '0' : ' ';
	ft_memset(fix, chr, ph->width - strlen);
	*str = ft_strcont(ph->flags, '-') ?
		ft_strmerge(*str, fix) : ft_strmerge(fix, *str);
}

void		conv_s(t_placeholder *ph, va_list ap)
{
	char	*str;

	(void)ph;
	str = va_arg(ap, char*);
	str = str != NULL ? str : "(null)";
	precision(ph, &str);
	width(ph, &str);
	ft_putstr_fd(str, 1);
	ft_strdel(&str);
}
