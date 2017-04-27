/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:22:12 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/26 18:45:55 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			process(const char *format, va_list ap)
{
	int				res;
	t_placeholder	*curr_ph;

	res = 0;
	while(*format)
	{
		if (*format == '%')
		{
			curr_ph = create_placeholder(&format);
			res += process_placeholder(curr_ph, ap);
		}
		ft_putchar(*format);
		res++;
		format++;
	}
	return (res);
}
