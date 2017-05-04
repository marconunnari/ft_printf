#include "libftprintf.h"

intmax_t	getintarg(t_placeholder *ph, va_list ap)
{
	if (ft_strequ(ph->length, "l") || ph->type == 'D')
		return (va_arg(ap, long));
	if (ft_strequ(ph->length, "hh"))
		return ((signed char)va_arg(ap, int));
	if (ft_strequ(ph->length, "h"))
		return ((short)va_arg(ap, int));
	if (ft_strequ(ph->length, "ll"))
		return (va_arg(ap, long long));
	if (ft_strequ(ph->length, "j") || ph->type == 'p')
		return (va_arg(ap, intmax_t));
	if (ft_strequ(ph->length, "z"))
		return (va_arg(ap, ssize_t));
	return (va_arg(ap, int));
}

uintmax_t	getuintarg(t_placeholder *ph, va_list ap)
{
	if (ft_strequ(ph->length, "j") || ph->type == 'p')
		return (va_arg(ap, uintmax_t));
	if (ft_strequ(ph->length, "l") || ph->type == 'U'
			|| ph->type == 'O')
		return (va_arg(ap, unsigned long));
	if (ft_strequ(ph->length, "hh"))
		return ((unsigned char)va_arg(ap, int));
	if (ft_strequ(ph->length, "h"))
		return ((unsigned short)va_arg(ap, int));
	if (ft_strequ(ph->length, "ll"))
		return (va_arg(ap, unsigned long long));
	if (ft_strequ(ph->length, "z"))
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned int));
}

void					manageprecision(t_placeholder *ph, char **str)
{
	char				*prefix;
	int					precision;
	int				strlen;

	precision = ft_atoi(ph->precision);
	if (ft_strequ(ph->precision, "0") && ft_strequ(*str, "0"))
	{
		REASSIGN(*str, ft_strdup(""));
		return ;
	}
	strlen = ft_strlen(*str);
	if (**str == '-')
		strlen--;
	if (ft_strlen(ph->precision) != 0 && precision >= strlen)
	{
		prefix = ft_strnew(precision - strlen);
		ft_memset(prefix, '0', precision - strlen);
		if (**str == '-')
		{
			prefix[0] = '-';
			**str = '0';
		}
		*str = ft_strmerge(prefix, *str);
	}
}

char					*printint(t_placeholder *ph, va_list ap)
{
	intmax_t			i;
	char				*str;

	i = getintarg(ph, ap);
	str = ft_imaxtoa(i);
	manageprecision(ph, &str);
	if (ft_strcont(ph->flags, '+') && ft_atoi(str) >= 0)
	{
		REASSIGN(str, ft_strjoin("+", str));
	}
	else
	{
		if (ft_strcont(ph->flags, ' ') && str[0] != '-')
			REASSIGN(str, ft_strjoin(" ", str));
	}
	return (str);
}

char					*printuint(t_placeholder *ph, va_list ap)
{
	uintmax_t			i;
	int					base;
	char				*str;

	i = getuintarg(ph, ap);
	base = 10;
	if (ph->type == 'x' || ph->type == 'X'
			|| ph->type == 'p')
		base = 16;
	if (ph->type == 'o' || ph->type == 'O')
		base = 8;
	if (ph->type == 'b')
		base = 2;
	str = ft_uimaxtoa_base(i, base);
	if (ph->type == 'p')
		REASSIGN(str, ft_strjoin("0x", str));
	manageprecision(ph, &str);
	if (ft_strcont(ph->flags,'#'))
	{
		if (i != 0)
		{
			if ((ph->type == 'x' || ph->type == 'X')
					&& (!(ft_strcont(ph->flags,'#') && ft_strcont(ph->flags,'0'))
					|| (ft_strcont(ph->flags,'-')))
					)
				REASSIGN(str, ft_strjoin("0x", str));
		}
		if (!ft_strequ(str, "0") && ph->type == 'o')
			REASSIGN(str, ft_strjoin("0", str));
	}
	if (ph->type == 'X')
		str = ft_strtoupper(str);
	return (str);
}
