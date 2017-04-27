/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_placeholder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:20:13 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/27 13:08:28 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int					printint(t_placeholder *ph, va_list ap)
{
	int		i;
	char	*str;

	(void)ph;
	i = va_arg(ap, int);
	str = ft_itoa(i);
	ft_putstr(str);
	return (ft_strlen(str));
}

int					printstr(t_placeholder *ph, va_list ap)
{
	char	*str;

	(void)ph;
	str = va_arg(ap, char*);
	ft_putstr(str);
	return (ft_strlen(str));
}

typedef int (*t_funct)(t_placeholder*, va_list);

typedef struct		s_typefunct
{
	char			*type;
	t_funct			f;
}					t_typefunct;

static t_typefunct			g_typefuncts[4] =
{
	{"s", &printstr},
	{"d", &printint},
	{"i", &printint},
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

int					process_placeholder(t_placeholder *ph, va_list ap)
{
	int		res;
	t_funct	f;

	f = get_funct(ph->type);
	res = f(ph, ap);
	free_placeholder(ph);
	return (res);
}
