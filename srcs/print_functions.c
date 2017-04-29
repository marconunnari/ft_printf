#include "libftprintf.h"

intmax_t	getintarg(t_placeholder *ph, va_list ap)
{
	if (ft_strequ(ph->length, "hh"))
		return ((signed char)va_arg(ap, int));
	if (ft_strequ(ph->length, "h"))
		return ((short)va_arg(ap, int));
	if (ft_strequ(ph->length, "l"))
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
	if (ft_strequ(ph->length, "l"))
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
	if (ph->type == 'o')
		base = 8;
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

char					*printchr(t_placeholder *ph, va_list ap)
{
	char	chr;
	char	*str;

	(void)ph;
	chr = va_arg(ap, int);
	str = ft_strnew(1);
	str[0] = chr;
	return (str);
}

char					*printstr(t_placeholder *ph, va_list ap)
{
	char			*str;
	unsigned int		precision;

	if (ft_strequ(ph->length, "l"))
		return (printwstr(ph, ap));
	else
		str = va_arg(ap, char*);
	if (str == NULL)
		str = "(null)";
	precision = ft_atoi(ph->precision);
	if (ft_strlen(ph->precision) != 0 && precision < ft_strlen(str))
		return (ft_strsub(str, 0, precision));
	return (ft_strdup(str));
}

char					*printwstr(t_placeholder *ph, va_list ap)
{
	wchar_t			*wstr;
	char			*str;
	unsigned int		precision;

	wstr = va_arg(ap, wchar_t*);
	if (wstr == NULL)
		wstr = L"(null)";
	precision = ft_atoi(ph->precision);
	str = (char*)wstr;
	if (ft_strlen(ph->precision) != 0 && precision < ft_strlen(str))
		return (ft_strsub(str, 0, precision));
	return (ft_strdup(str));
}

char					*printpercent(t_placeholder *ph, va_list ap)
{
	char	*str;

	(void)ph;
	(void)ap;
	str = ft_strnew(1);
	str[0] = '%';
	return (str);
}
