/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 18:33:48 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/07 18:34:10 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			conv_x(t_placeholder *ph, va_list ap)
{
	unsigned int	u;
	char		*str;

	(void)ph;
	u = va_arg(ap, unsigned int);
	str = ft_uimaxtoa_base(u, 16);
	ft_putstr_fd(str, 1);
	ft_strdel(&str);
}
