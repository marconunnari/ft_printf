/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_placeholder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:21:25 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/04 19:24:47 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*g_flags[6] = {"#", "0", "-", "+", " ", NULL};
static char		*g_lengths[7] = {"hh", "h", "ll", "l", "j", "z", NULL};
static char		g_types[17] = {'s', 'S', 'p', 'd', 'D', 'i',
	'o', 'O', 'u', 'U', 'x', 'X', 'c', 'C', '%', 'b', 0};

void			get_flags(const char **formatptr, t_placeholder *ph)
{
	char			*s;

	while ((s = ft_contstr(g_flags, *formatptr)))
	{
		REASSIGN(ph->flags, ft_strjoin(ph->flags, s));
		*formatptr += 1;
	}
}

void			get_width(const char **formatptr, t_placeholder *ph)
{
	while (ft_isdigit(**formatptr))
	{
		ph->width = ft_strappend(ph->width, **formatptr);
		*formatptr += 1;
	}
}

void			get_precision(const char **formatptr, t_placeholder *ph)
{
	if (**formatptr == '.')
	{
		*formatptr += 1;
		while(ft_isdigit(**formatptr))
		{
			ph->precision = ft_strappend(ph->precision, **formatptr);
			*formatptr += 1;
		}
		if (ft_strlen(ph->precision) == 0)
			ph->precision = ft_strappend(ph->precision, '0');
	}
}

void			get_length(const char **formatptr, t_placeholder *ph)
{
	char			*s;

	if ((s = ft_contstr(g_lengths, *formatptr)))
	{
		REASSIGN(ph->length, ft_strdup(s));
		*formatptr = *formatptr + ft_strlen(s);
	}
}

t_placeholder	*create_placeholder(const char **format)
{
	const char		*formatptr;
	t_placeholder	*ph;
	int			i;

	formatptr = *format + 1;
	ph = init_placeholder();
	i = 0;
	while (i < 4)
	{
		get_flags(&formatptr, ph);
		get_width(&formatptr, ph);
		get_precision(&formatptr, ph);
		get_length(&formatptr, ph);
		i++;
	}
	if (ft_strcont(g_types, *formatptr))
	{
		ph->type = *formatptr;
		formatptr++;
	}
	else
		ph = NULL;
	*format = *format + (formatptr - *format);
	return (ph);
}
