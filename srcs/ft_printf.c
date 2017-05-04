/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:46:10 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/04 18:41:52 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_putstr(char const *s)
{
	if (!s)
		return ;
	while (*s)
	{
		if (*s == 1)
			ft_putchar('\0');
		else
			ft_putchar(*s);
		s++;
	}
}

int			ft_vasprintf(char **str, const char *format, va_list ap)
{
	char		*res;
	char		*tmp;
	t_placeholder	*curr_ph;

	*str = NULL;
	res = ft_strnew(0);
	while(*format)
	{
		if (*format == '%')
		{
			curr_ph = create_placeholder(&format);
			if (curr_ph)
			{
				tmp = process_placeholder(curr_ph, ap);
				if (tmp)
					res = ft_strmerge(res, tmp);
			}
		}
		else
		{
			res = ft_strappend(res, *format);
			format++;
		}
	}
	*str = res;
	return (ft_strlen(res));
}

int				ft_asprintf(char **str, const char *format, ...)
{
	va_list		ap;
	int		res;

	va_start(ap, format);
	res = ft_vasprintf(str, format, ap);
	va_end(ap);
	return (res);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*str;
	int		res;

	va_start(ap, format);
	res = ft_vasprintf(&str, format, ap);
	if (str)
	{
		ft_putstr(str);
		ft_strdel(&str);
	}
	va_end(ap);
	return (res);
}
