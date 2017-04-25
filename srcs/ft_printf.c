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

typedef struct	s_placeholder
{
	char		*flags;
	char		*width;
	char		*precision;
	char		*length;
	char		*type;
}		t_placeholder;

char	*g_flags[6] = {"#", "0", "-", "+", " ", NULL};
char	*g_lengths[7] = {"hh", "h", "l", "ll", "j","z", NULL};
char	*g_types[15] = {"s","S","p","d","D","i","o","O","u","U","x","X","c","C", NULL};

int		process_placeholder(t_placeholder ph, va_list ap)
{
}

char		*contains(char **arr, char *s)
{
	int	i;
	char	*strsub;

	i = 0;
	while (arr[i])
	{
		strsub = ft_strsub(s, 0, ft_strlen(arr[i]));
		if (ft_strequ(arr[i], strsub))
			return (arr[i]);
		i++;
	}
	return (NULL);
}

t_placeholder	init_placeholder()
{
	t_placeholder	res;

	res.flags = ft_strnew(0);
	res.width = ft_strnew(0);
	res.precision = ft_strnew(0);
	res.length = ft_strnew(0);
	res.type = ft_strnew(0);
	return (res);
}

t_placheholder	create_placeholder(const char **restrict format)
{
	char	*s;
	t_placeholder ph;

	ph = init_placeholder();
	while(**format)
	{
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
		if ((s = contains(g_lengths, *format)))
		{
			ph.type = s;
			*format += 1;
		}
		else
			exit(-1);
	}
}

int		print(const char *restrict format, va_list ap)
{
	int		res;
	t_placeholder	curr_ph;

	while(*format)
	{
		if (*format == '%')
		{
			curr_ph = create_placeholder(&format);
			res += process_placeholder(curr_ph, ap);
		}
		ft_putchar(*format);
		res++
		format++;
	}
	return (res);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int		res;

	va_start(ap, format);
	res = print(format, ap);
	va_end(ap);
	return (res);
}
