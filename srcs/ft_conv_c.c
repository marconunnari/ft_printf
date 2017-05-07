/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 17:43:37 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/07 17:43:39 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		conv_c(t_placeholder *ph, va_list ap)
{
	char	chr;

	(void)ph;
	chr = (char)va_arg(ap, int);
	ft_putchar_fd(chr, 1);
}
