/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_du.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 19:09:41 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/07 19:09:43 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		conv_du(t_placeholder *ph, va_list ap)
{
	long		d;
	char		*str;

	(void)ph;
	d = va_arg(ap, long);
	str = ft_imaxtoa(d);
	ft_putstr_fd(str, 1);
	ft_strdel(&str);
}
