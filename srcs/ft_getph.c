#include "libftprintf.h"

static const char *g_flags = "#0-+";
static const char *g_lengths = "hljz";
static const char *g_types = "sSpdDioOuUxXcC";

void			get_parameter(const char **format, t_placeholder *ph)
{
	(void)format;
	(void)ph;
}

void			get_flags(const char **format, t_placeholder *ph)
{
	while (ft_strcont(g_flags, **format))
	{
		ft_strappend(ph->flags, **format);
		*format += 1;
	}
}

void			get_width(const char **format, t_placeholder *ph)
{
	while (ft_isdigit(**format))
	{
		ph->width = ph->width * 10 + (**format - '0');
		*format += 1;
	}
}

void			get_precision(const char **format, t_placeholder *ph)
{
	while (**format == '.')
	{
		*format += 1;
		while(ft_isdigit(**format))
		{
			ph->precision = ph->precision * 10 + (**format - '0');
			*format += 1;
		}
	}
}

void			get_length(const char **format, t_placeholder *ph)
{
	while (ft_strcont(g_lengths, **format))
	{
		ft_strappend(ph->length, **format);
		*format += 1;
	}
}

void			get_type(const char **format, t_placeholder *ph)
{
	if (ft_strcont(g_types, **format))
	{
		ph->type = **format;
		*format += 1;
	}
}
