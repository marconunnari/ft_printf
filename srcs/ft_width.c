/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:13:10 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/09 17:13:23 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		width(t_placeholder *ph, char **str)
{
	char		*fix;
	char		chr;
	int			strlen;

	strlen = ft_strlen(*str);
	IFRETURNVOID(ph->width < strlen);
	fix = ft_strnew(ph->width - strlen);
	chr = ft_strcont(ph->flags, '0') && !ft_strcont(ph->flags, '-') ? '0' : ' ';
	ft_memset(fix, chr, ph->width - strlen);
	*str = ft_strcont(ph->flags, '-') ?
		ft_strmerge(*str, fix) : ft_strmerge(fix, *str);
}
