#include "libftprintf.h"

typedef void (*t_conv)(t_placeholder*, va_list);

typedef struct		s_typeconv
{
	char			type;
	t_conv			conv;
}			t_typeconv;

static t_typeconv	g_typeconvs[3] =
{
	{'s', &conv_s},
	{'d', &conv_d},
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
