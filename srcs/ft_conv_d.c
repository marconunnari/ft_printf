/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:43:03 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/07 16:26:41 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		conv_d(t_placeholder *ph, va_list ap)
{
	int	d;
	char	*str;

	(void)ph;
	d = va_arg(ap, int);
	str = ft_imaxtoa(d);
	ft_putstr_fd(str, 1);
	ft_strdel(&str);
}
