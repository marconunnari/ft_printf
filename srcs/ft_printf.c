/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 17:39:33 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/06 18:58:55 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

extern int g_res;

int				ft_printf(const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	do_print(format, ap);
	va_end(ap);
	return (g_res);
}
