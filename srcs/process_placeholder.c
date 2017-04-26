/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_placeholder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:20:13 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/26 18:20:15 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		process_placeholder(t_placeholder *ph, va_list ap)
{
	char	*s;

	if(ft_strequ(ph->type, "s"))
	{
		s = va_arg(ap, char*);
		free(ph);
		return (ft_strlen(s));
	}
	free(ph);
	return (0);
}
