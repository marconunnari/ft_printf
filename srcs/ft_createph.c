/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:43:21 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/09 18:22:24 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_placeholder	*initph()
{
	t_placeholder	*res;

	res = (t_placeholder*)malloc(sizeof(t_placeholder));
	res->parameter = -1;
	res->flags = ft_strnew(0);
	res->width = 0;
	res->precision = -1;
	res->length = ft_strnew(0);
	res->type = 0;
	return (res);
}

void		freeph(t_placeholder *ph)
{
	free(ph->flags);
	free(ph->length);
	free(ph);
}

t_placeholder	*createph(const char **format)
{
	t_placeholder	*ph;
	int			i;

	ph = initph();
	get_parameter(format, ph);
	i = 0;
	while (i < 4)
	{
		get_flags(format, ph);
		get_width(format, ph);
		get_precision(format, ph);
		get_length(format, ph);
		i++;
	}
	get_type(format, ph);
	return (ph);
}
