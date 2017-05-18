/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_wc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 18:01:40 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/10 13:59:32 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		conv_wc(t_placeholder *ph, va_list ap)
{
	wchar_t		wchr;

	(void)ph;
	wchr = va_arg(ap, wchar_t);
	wchr == 0 ? ft_printf_putchar(0) : ft_printf_putwchar(wchr);
}
