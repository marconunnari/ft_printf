/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:43:28 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/10 17:14:54 by mnunnari         ###   ########.fr       */
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
	char	*g_flags = "#0-+ ";

	while (ft_strcont(g_flags, **format))
	{
		ph->flags = ft_strappend(ph->flags, **format);
		*format += 1;
	}
}

void			get_width(const char **format, t_placeholder *ph)
{
	while (ft_isdigit(**format))
	{
		ph->width = ph->width * 10 + (**format - '0');
		*format += 1;
	}
}

void			get_precision(const char **format, t_placeholder *ph)
{
	while (**format == '.')
	{
		*format += 1;
		ph->precision = 0;
		while(ft_isdigit(**format))
		{
			ph->precision = ph->precision * 10 + (**format - '0');
			*format += 1;
		}
	}
}

void			get_length(const char **format, t_placeholder *ph)
{
	char	*g_lengths = "hljz";

	while (ft_strcont(g_lengths, **format))
	{
		ph->length = ft_strappend(ph->length, **format);
		*format += 1;
	}
}

void			get_type(const char **format, t_placeholder *ph)
{
	if (**format)
	{
		ph->type = **format;
		*format += 1;
	}
}
