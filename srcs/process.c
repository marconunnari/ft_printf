/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:22:12 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/27 19:36:26 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		process(char **ret, const char *format, va_list ap)
{
	t_placeholder	*curr_ph;

	*ret = ft_strnew(0);
	while(*format)
	{
		if (*format == '%')
		{
			curr_ph = create_placeholder(&format);
			*ret = ft_strmerge(*ret, process_placeholder(curr_ph, ap));
		}
		ft_strappend(*ret, *format);
		format++;
	}
}
