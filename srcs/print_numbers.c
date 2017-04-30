#include "libftprintf.h"

intmax_t	getintarg(t_placeholder *ph, va_list ap)
{
	if (ft_strequ(ph->length, "hh"))
		return ((signed char)va_arg(ap, int));
	if (ft_strequ(ph->length, "h"))
		return ((short)va_arg(ap, int));
	if (ft_strequ(ph->length, "l") || ph->type == 'D')
		return (va_arg(ap, long));
	if (ft_strequ(ph->length, "ll"))
		return (va_arg(ap, long long));
	if (ft_strequ(ph->length, "j") || ph->type == 'p')
		return (va_arg(ap, intmax_t));
	if (ft_strequ(ph->length, "z"))
		return (va_arg(ap, ssize_t));
	return (va_arg(ap, int));
}

char					*printint(t_placeholder *ph, va_list ap)
{
	intmax_t			i;
	char				*str;

	i = getintarg(ph, ap);
	str = ft_imaxtoa(i);
	if (ft_strcont(ph->flags, '+') && str[0] != '-')
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

uintmax_t	getuintarg(t_placeholder *ph, va_list ap)
{
	if (ft_strequ(ph->length, "hh"))
		return ((unsigned char)va_arg(ap, int));
	if (ft_strequ(ph->length, "h"))
		return ((unsigned short)va_arg(ap, int));
	if (ft_strequ(ph->length, "l") || ph->type == 'U'
			|| ph->type == 'O')
		return (va_arg(ap, unsigned long));
	if (ft_strequ(ph->length, "ll"))
		return (va_arg(ap, unsigned long long));
	if (ft_strequ(ph->length, "j") || ph->type == 'p')
		return (va_arg(ap, uintmax_t));
	if (ft_strequ(ph->length, "z"))
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned int));
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
	if (ft_strcont(ph->flags,'#'))
	{
		if (!ft_strequ(str, "0"))
		{
			if (ph->type == 'x' || ph->type == 'X')
				REASSIGN(str, ft_strjoin("0x", str));
			if (ph->type == 'o')
				REASSIGN(str, ft_strjoin("0", str));
		}
	}
	if (ph->type == 'X')
		str = ft_strtoupper(str);
	return (str);
}
