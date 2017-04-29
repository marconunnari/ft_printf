/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_placeholder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:20:13 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/29 18:34:39 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

typedef char *(*t_funct)(t_placeholder*, va_list);

typedef struct		s_typefunct
{
	char			type;
	t_funct			f;
}					t_typefunct;

static t_typefunct			g_typefuncts[11] =
{
	{'s', &printstr},
	{'c', &printchr},
	{'d', &printint},
	{'i', &printint},
	{'u', &printuint},
	{'x', &printuint},
	{'X', &printuint},
	{'o', &printuint},
	{'p', &printuint},
	{'%', &printpercent},
	{0, NULL}
};

t_funct		get_funct(char type)
{
	int		i = 0;

	while (g_typefuncts[i].type)
	{
		if (g_typefuncts[i].type == type)
			return (g_typefuncts[i].f);
		i++;
	}
	return (NULL);
}

char					*width(char *str, t_placeholder *ph)
{
	int		width;
	int		strlen;
	char		*fix;

	width = ft_atoi(ph->width);
	strlen = ft_strlen(str);
	if (ft_strlen(ph->width) != 0 && width > strlen)
	{
		fix = ft_strnew(width - strlen);
		if (ft_strcont(ph->flags, '0'))
			ft_memset(fix, '0', width - strlen);
		else
			ft_memset(fix, ' ', width - strlen);
		if (ft_strcont(ph->flags, '-'))
			str = ft_strmerge(str, fix);
		else
			str = ft_strmerge(fix, str);
	}
	return (str);
}

char					*process_placeholder(t_placeholder *ph, va_list ap)
{
	char		*res;
	t_funct		convert;

	convert = get_funct(ph->type);
	IFRETURN(!convert, NULL);
	res = convert(ph, ap);
	res = width(res, ph);
	free_placeholder(ph);
	return (res);
}
