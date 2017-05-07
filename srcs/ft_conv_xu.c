/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_xu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 19:02:19 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/07 19:04:26 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			conv_xu(t_placeholder *ph, va_list ap)
{
	unsigned int	u;

	(void)ph;
	u = va_arg(ap, unsigned int);
	ft_putstr_fd(ft_strtoupper(ft_uimaxtoa_base(u, 16)), 1);
}
