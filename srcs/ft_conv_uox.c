/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_uox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:04:11 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/14 19:26:39 by mnunnari         ###   ########.fr       */
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
