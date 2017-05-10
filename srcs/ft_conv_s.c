/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:42:54 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/10 18:29:08 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		precision(t_placeholder *ph, char **str)
{
	IFRETURNVOID(ph->precision == -1 || ph->type != 's');
	REASSIGN(*str, ft_strsub(*str, 0, ph->precision));
}

void		conv_s(t_placeholder *ph, va_list ap)
{
	char	*str;

	IFRETURN(ft_strequ(ph->length, "l"), conv_ws(ph, ap))
	str = NULL;
	if (ph->type =='s')
	{
		str = va_arg(ap, char*);
		if (str == NULL)
			str = "(null)";
		str = ft_strdup(str);
	}
	else
	{
		str = ft_strnew(1);
		str[0] = ph->type;
	}
	precision(ph, &str);
	width(ph, &str);
	ft_putstr_fd(str, 1);
	ft_strdel(&str);
}
