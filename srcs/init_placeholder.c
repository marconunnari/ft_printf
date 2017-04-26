/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_placeholder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:21:03 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/26 18:21:06 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_placeholder	*init_placeholder()
{
	t_placeholder	*res;

	res = (t_placeholder*)malloc(sizeof(t_placeholder));
	res->flags = ft_strnew(0);
	res->width = ft_strnew(0);
	res->precision = ft_strnew(0);
	res->length = ft_strnew(0);
	res->type = ft_strnew(0);
	return (res);
}
