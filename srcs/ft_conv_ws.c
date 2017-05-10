/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ws.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:25:30 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/10 19:14:05 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char					*wstrtostr(wchar_t *wstr)
{
	char		*str;
	char		*tmp;
	int		i;

	i = 0;
	str = ft_strnew(0);
	while (*wstr)
	{
		tmp = wchartostr(*wstr);
		i += ft_strlen(tmp);
		str = ft_strmerge(str, tmp);
		wstr++;
	}
	return (str);
}

char					*wstrtostrprec(wchar_t *wstr, int len)
{
	char		*str;
	char		*tmp;
	int		i;

	i = 0;
	str = ft_strnew(0);
	while (*wstr && i <= len)
	{
		tmp = wchartostr(*wstr);
		i += ft_strlen(tmp);
		if (i <= len)
			str = ft_strmerge(str, tmp);
		else
			free(tmp);
		wstr++;
	}
	return (str);
}

void		conv_ws(t_placeholder *ph, va_list ap)
{
	wchar_t		*wstr;
	char		*str;

	(void)ph;
	wstr = va_arg(ap, wchar_t*);
	wstr = wstr == NULL ? L"(null)" : wstr;
	if (ph->precision != -1)
		str = wstrtostrprec(wstr, ph->precision);
	else
		str = wstrtostr(wstr);
	width(ph, &str);
	ft_putstr_fd(str, 1);
	ft_strdel(&str);
}
