/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:42:54 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/09 17:13:03 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		precision(t_placeholder *ph, char **str)
{
	*str = ft_strdup(*str);
	IFRETURNVOID(ph->precision == -1);
	*str = ft_strsub(*str, 0, ph->precision);
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
