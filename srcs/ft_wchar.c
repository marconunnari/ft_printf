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

static t_sizewchr	g_sizewchrs[5] =
{
	{(1 << 7), &onebyte},
	{(1 << 11), &twobytes},
	{(1 << 16), &threebytes},
	{(1 << 21), &fourbytes},
	{0, NULL}
};

char				*wchartostr(wchar_t wchr)
{
	int			i;

	i = 0;
	while (g_sizewchrs[i].size)
	{
		if (wchr < g_sizewchrs[i].size)
			return (g_sizewchrs[i].tostr(wchr));
		i++;
	}
	return (NULL);
}
