/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numprec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 18:19:15 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/14 19:20:34 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	numprec(t_placeholder *ph, char **str, int is_zero)
{
	char		*fix;
	int			strlen;

	if (ph->precision == 0 && is_zero
		&& !(ft_tolower(ph->type) == 'o' && ft_strcont(ph->flags, '#')))
	{
		REASSIGN(*str, ft_strdup(""));
		return ;
	}
	strlen = ft_strlen(*str);
	IFRETURNVOID(ph->precision < strlen);
	if (ft_tolower(ph->type) == 'o' && ft_strcont(ph->flags, '#'))
		ph->precision--;
	fix = ft_strnew(ph->precision - strlen);
	ft_memset(fix, '0', ph->precision - strlen);
	ft_strremove(ph->flags, '0');
	*str = ft_strmerge(fix, *str);
}
