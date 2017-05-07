/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 18:59:02 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/07 16:25:50 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			do_print(const char *format, va_list ap)
{
	while (*format)
	{
		if (*format == '%')
			do_conv(&format, ap);
		else
			ft_putchar_fd(*format++, 1);
	}
}
