/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 18:33:48 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/07 18:50:58 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			conv_p(t_placeholder *ph, va_list ap)
{
	uintmax_t	u;
	char		*str;

	(void)ph;
	u = va_arg(ap, uintmax_t);
	ft_putstr_fd("0x", 1);
	str = ft_uimaxtoa_base(u, 16);
	ft_putstr_fd(str, 1);
	ft_strdel(&str);
}
