/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 18:59:02 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/06 19:32:43 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			do_print(const char *format, va_list ap)
{
	while (*format)
	{
		while (*format != '%')
			ft_putchar(*format++);
		while (*format == '%')
			do_conv(&format, ap);
	}
}
