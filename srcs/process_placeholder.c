/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_placeholder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:20:13 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/27 18:26:49 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

typedef char *(*t_funct)(t_placeholder*, va_list);

typedef struct		s_typefunct
{
	char			*type;
	t_funct			f;
}					t_typefunct;

static t_typefunct			g_typefuncts[6] =
{
	{"s", &printstr},
	{"c", &printchr},
	{"d", &printint},
	{"i", &printint},
	{"u", &printuint},
	{NULL, NULL}
};

t_funct		get_funct(char *type)
{
	int		i = 0;

	while (g_typefuncts[i].type)
	{
		if (ft_strequ(g_typefuncts[i].type, type))
			return (g_typefuncts[i].f);
		i++;
	}
	return (NULL);
}

char					*process_placeholder(t_placeholder *ph, va_list ap)
{
	char		*res;
	t_funct	f;

	f = get_funct(ph->type);
	IFRETURN(!f, NULL);
	res = f(ph, ap);
	free_placeholder(ph);
	return (res);
}
