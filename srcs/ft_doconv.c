/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doconv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:43:44 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/10 18:25:03 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

typedef void (*t_conv)(t_placeholder*, va_list);

typedef struct		s_typeconv
{
	char			type;
	t_conv			conv;
}			t_typeconv;

static t_typeconv	g_typeconvs[16] =
{
	{'s', &conv_s},
	{'S', &conv_ws},
	{'d', &conv_d},
	{'D', &conv_d},
	{'i', &conv_d},
	{'c', &conv_c},
	{'C', &conv_wc},
	{'u', &conv_u},
	{'U', &conv_u},
	{'p', &conv_x},
	{'x', &conv_x},
	{'X', &conv_x},
	{'o', &conv_o},
	{'O', &conv_o},
	{0, NULL}
};

t_conv		get_conv(char type)
{
	int		i = 0;

	while (g_typeconvs[i].type)
	{
		if (g_typeconvs[i].type == type)
			return (g_typeconvs[i].conv);
		i++;
	}
	return (&conv_s);
}

void			do_conv(const char **format, va_list ap)
{
	t_placeholder	*ph;
	t_conv		conv;

	*format += 1;
	ph = createph(format);
	IFRETURN(!ph->type, freeph(ph));
	conv = get_conv(ph->type);
	IFRETURNVOID(!conv);
	conv(ph, ap);
	freeph(ph);
}
