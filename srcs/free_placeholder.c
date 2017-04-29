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

void	free_placeholder(t_placeholder *ph)
{
	free(ph->flags);
	free(ph->width);
	free(ph->precision);
	free(ph->length);
	free(ph);
}
