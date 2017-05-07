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

	(void)ph;
	d = va_arg(ap, int);
	ft_putstr_fd(ft_imaxtoa(d), 1);
}
