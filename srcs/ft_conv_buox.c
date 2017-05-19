/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_buox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:44:49 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/19 14:44:51 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			conv_x(t_placeholder *ph, va_list ap)
{
	conv_ubase(ph, ap, 16);
}

void			conv_o(t_placeholder *ph, va_list ap)
{
	conv_ubase(ph, ap, 8);
}

void			conv_u(t_placeholder *ph, va_list ap)
{
	conv_ubase(ph, ap, 10);
}

void			conv_b(t_placeholder *ph, va_list ap)
{
	conv_ubase(ph, ap, 2);
}
