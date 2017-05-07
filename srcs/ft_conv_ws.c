/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ws.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:25:30 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/07 16:29:33 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		conv_ws(t_placeholder *ph, va_list ap)
{
	wchar_t		*wstr;

	(void)ph;
	wstr = va_arg(ap, wchar_t*);
	wstr = wstr == NULL ? L"(null)" : wstr;
	ft_putwstr_fd(wstr, 1);
}
