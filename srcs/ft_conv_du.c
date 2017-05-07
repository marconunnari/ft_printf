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

	(void)ph;
	d = va_arg(ap, long);
	ft_putstr_fd(ft_imaxtoa(d), 1);
}
