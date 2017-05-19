/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:43:28 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/19 14:45:16 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			get_parameter(const char **format, t_placeholder *ph)
{
	(void)format;
	(void)ph;
}

void			get_flags(const char **format, t_placeholder *ph)
{
	char	*g_flags;

	g_flags = "#0-+ ";
	while (ft_strcont(g_flags, **format))
	{
		ph->flags = ft_strappend(ph->flags, **format);
		*format += 1;
	}
}

void			get_width(const char **format, t_placeholder *ph, va_list ap)
{
	if (**format == 42)
	{
		ph->width = va_arg(ap, int);
		if (ph->width < 0)
		{
			ph->width *= -1;
			ph->flags = ft_strappend(ph->flags, '-');
		}
		*format += 1;
	}
	else if (ft_isdigit(**format))
	{
		ph->width = 0;
		while (ft_isdigit(**format))
		{
			ph->width = ph->width * 10 + (**format - '0');
			*format += 1;
		}
	}
}

void			get_precision(const char **format, t_placeholder *ph,
								va_list ap)
{
	while (**format == '.')
	{
		*format += 1;
		ph->precision = 0;
		if (**format == 42)
		{
			ph->precision = va_arg(ap, int);
			if (ph->precision < 0)
				ph->precision = -1;
			*format += 1;
		}
		while (ft_isdigit(**format))
		{
			ph->precision = ph->precision * 10 + (**format - '0');
			*format += 1;
		}
	}
}

void			get_length(const char **format, t_placeholder *ph)
{
	char	*g_lengths;

	g_lengths = "hljz";
	while (ft_strcont(g_lengths, **format))
	{
		ph->length = ft_strappend(ph->length, **format);
		*format += 1;
	}
}
