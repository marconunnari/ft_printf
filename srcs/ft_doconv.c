/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doconv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:43:44 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/07 19:16:27 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

typedef void (*t_conv)(t_placeholder*, va_list);

typedef struct		s_typeconv
{
	char			type;
	t_conv			conv;
}			t_typeconv;

static t_typeconv	g_typeconvs[14] =
{
	{'s', &conv_s},
	{'S', &conv_ws},
	{'d', &conv_d},
	{'D', &conv_du},
	{'i', &conv_d},
	{'c', &conv_c},
	{'C', &conv_wc},
	{'%', &conv_pc},
	{'u', &conv_u},
	{'x', &conv_x},
	{'X', &conv_xu},
	{'o', &conv_o},
	{'p', &conv_p},
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
	return (NULL);
}

void			do_conv(const char **format, va_list ap)
{
	t_placeholder	*ph;
	t_conv		conv;

	*format += 1;
	ph = createph(format);
	IFRETURNVOID(!ph->type);
	conv = get_conv(ph->type);
	IFRETURNVOID(!conv);
	conv(ph, ap);
	freeph(ph);
}
