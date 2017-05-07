/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 18:37:11 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/07 18:37:23 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			conv_o(t_placeholder *ph, va_list ap)
{
	unsigned int	u;

	(void)ph;
	u = va_arg(ap, unsigned int);
	ft_putstr_fd(ft_uimaxtoa_base(u, 8), 1);
}
