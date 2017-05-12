/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:44:03 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/07 16:33:31 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char				*onebyte(wchar_t wchr)
{
	char		*str;

	str = ft_strnew(1);
	str[0] = (unsigned char)(wchr);
	return (str);
}

char				*twobytes(wchar_t wchr)
{
	char		*str;

	str = ft_strnew(2);
	str[0] = (unsigned char)((wchr >> 6) | 0xC0);
	str[1] = (unsigned char)((wchr & 0x3F) | 0x80);
	return (str);
}

char				*threebytes(wchar_t wchr)
{
	char		*str;

	str = ft_strnew(3);
	str[0] = (unsigned char)(((wchr >> 12)) | 0xE0);
	str[1] = (unsigned char)(((wchr >> 6) & 0x3F) | 0x80);
	str[2] = (unsigned char)((wchr & 0x3F) | 0x80);
	return (str);
}

char				*fourbytes(wchar_t wchr)
{
	char		*str;

	str = ft_strnew(4);
	str[0] = (unsigned char)(((wchr >> 18)) | 0xF0);
	str[1] = (unsigned char)(((wchr >> 12) & 0x3F) | 0x80);
	str[2] = (unsigned char)(((wchr >> 6) & 0x3F) | 0x80);
	str[3] = (unsigned char)((wchr & 0x3F) | 0x80);
	return (str);
}

char				*wchartostr(wchar_t wchr)
{
	if (wchr < (MB_CUR_MAX == 1 ? 0xFF : 0x7F))
		return onebyte(wchr);
	else if (wchr < (1 << 11))
		return twobytes(wchr);
	else if (wchr < (1 << 16))
		return threebytes(wchr);
	else if (wchr < (1 << 21))
		return fourbytes(wchr);
	else
		return (NULL);
}
