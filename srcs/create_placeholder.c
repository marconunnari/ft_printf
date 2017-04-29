/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_placeholder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:21:25 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/27 10:47:20 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*g_flags[6] = {"#", "0", "-", "+", " ", NULL};
static char		*g_lengths[7] = {"hh", "h", "ll", "l", "j", "z", NULL};
static char		g_types[16] = {'s', 'S', 'p', 'd', 'D', 'i',
	'o', 'O', 'u', 'U', 'x', 'X', 'c', 'C', '%', 0};

t_placeholder	*create_placeholder(const char **format)
{

	char			*s;
	const char		*formatptr;
	t_placeholder	*ph;

	formatptr = *format + 1;
	ph = init_placeholder();
	while ((s = ft_contstr(g_flags, formatptr)))
	{
		REASSIGN(ph->flags, ft_strjoin(ph->flags, s));
		formatptr++;
	}
	while (ft_isdigit(*formatptr))
	{
		ph->width = ft_strappend(ph->width, *formatptr);
		formatptr++;
	}
	if (*formatptr == '.')
	{
		formatptr++;
		while(ft_isdigit(*formatptr))
		{
			ph->precision = ft_strappend(ph->precision, *formatptr);
			formatptr++;
		}
	}
	if ((s = ft_contstr(g_lengths, formatptr)))
	{
		REASSIGN(ph->length, ft_strjoin(ph->length, s));
		formatptr = formatptr + ft_strlen(s);
	}
	if (ft_strcont(g_types, *formatptr))
	{
		ph->type = *formatptr;
		formatptr++;
	}
	else
		exit(-1);
	*format = *format + (formatptr - *format);
	return (ph);
}
