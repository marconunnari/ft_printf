/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:46:10 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/26 19:06:28 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*str;
	int		res;

	va_start(ap, format);
	res = ft_vasprintf(&str, format, ap);
	ft_putstr(str);
	ft_strdel(&str);
	va_end(ap);
	return (res);
}
