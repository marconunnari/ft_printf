/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_placeholder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:21:25 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/26 19:06:41 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*g_flags[6] = {"#", "0", "-", "+", " ", NULL};
char			*g_lengths[7] = {"hh", "h", "l", "ll", "j", "z", NULL};
char			*g_types[15] = {"s", "S", "p", "d", "D", "i",
	"o", "O", "u", "U", "x", "X", "c", "C", NULL};

t_placeholder	*create_placeholder(const char **format)
{
	char			*s;
	const char		*formatptr;
	t_placeholder	*ph;

	formatptr = *format + 1;
	ph = init_placeholder();
	while(**format)
	{
		if ((s = ft_contstr(g_types, *format)))
		{
			ph->type = ft_strjoin(ph->type, s);
			*format += 1;
		}
		else
			exit(-1);
	}
	return (ph);
}

		/*
		while ((s = contains(g_flags, *format)))
		{
			ph.flags = ft_strmerge(ph.flags, s);
			*format += 1;
		}
		while (ft_isdigit(**format))
		{
			ph.width = ft_strappend(ph.width, **format);
			*format += 1;
		}
		if (**format == '.')
		{
			while(ft_isdigit(**format))
			{
				ph.precision = ft_strappend(ph.precision, **format);
				*format += 1;
			}
		}
		while ((s = contains(g_lengths, *format)))
		{
			ph.length = ft_strmerge(ph.length, s);
			*format += 1;
		}
		*/

