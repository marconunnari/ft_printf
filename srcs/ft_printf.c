/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:46:10 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/24 20:12:56 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

typedef struct		s_conversion
{
	char		c;
	int		(*f)(va_list);
}			t_conversion;

int		ft_convertstring(va_list ap)
{
	char	*s;
	
	s = va_arg(ap, char *);
	ft_putstr((char*)s);
	return (ft_strlen((char*)s));
}

t_conversion arr[1] =
{
	{'s', &ft_convertstring}
};


int			process(const char *restrict format, va_list ap)
{
	int		res;
	int		i;

	res = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			i = 0;
			while(i < 1)
			{
				if (arr[i].c == *format)
					res += arr[i].f(ap);
				i++;
			}
		}
		else
			ft_putchar(*format);
		format++;
		res++;
	}
	return (res);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int		res;

	va_start(ap, format);
	res = process(format, ap);
	va_end(ap);
	return (res);
}
