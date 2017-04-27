/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_placeholder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:20:13 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/27 19:42:07 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char				*printuint(t_placeholder *ph, va_list ap)
{
	unsigned int		i;
	char				*str;

	(void)ph;
	i = va_arg(ap, unsigned int);
	str = ft_ulltoa_base(i, 10);
	return (ft_strdup(str));
}

char				*printint(t_placeholder *ph, va_list ap)
{
	int		i;
	char	*str;

	(void)ph;
	i = va_arg(ap, int);
	str = ft_lltoa(i);
	return (ft_strdup(str));
}

char					*printchr(t_placeholder *ph, va_list ap)
{
	char	chr;
	char	*str;

	(void)ph;
	chr = va_arg(ap, int);
	str = ft_strnew(1);
	str[0] = chr;
	return (ft_strdup(str));
}

char					*printstr(t_placeholder *ph, va_list ap)
{
	char	*str;

	(void)ph;
	str = va_arg(ap, char*);
	return (ft_strdup(str));
}

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

char				*process_placeholder(t_placeholder *ph, va_list ap)
{
	char	*res;
	t_funct	f;

	f = get_funct(ph->type);
	res = f(ph, ap);
	free_placeholder(ph);
	return (res);
}
