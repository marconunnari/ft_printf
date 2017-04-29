#include "libftprintf.h"
#include <inttypes.h>

char					*printptr(t_placeholder *ph, va_list ap)
{
	intmax_t			i;
	char				*str;

	(void)ph;
	i = va_arg(ap, intmax_t);
	str = ft_ulltoa_base(i, 16);
	REASSIGN(str, ft_strjoin("0x", str));
	return (str);
}
char					*printuint(t_placeholder *ph, va_list ap)
{
	unsigned int		i;
	int					base;
	char				*str;

	(void)ph;
	i = va_arg(ap, unsigned int);
	base = 10;
	if (ph->type == 'x' || ph->type == 'X'
			|| ph->type == 'p')
		base = 16;
	if (ph->type == 'o')
		base = 8;
	str = ft_ulltoa_base(i, base);
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

char					*printint(t_placeholder *ph, va_list ap)
{
	int		i;
	char	*str;

	i = va_arg(ap, int);
	str = ft_lltoa(i);
	if (ft_strcont(ph->flags, '+') && str[0] != '-')
		REASSIGN(str, ft_strjoin("+", str));
	if (ft_strcont(ph->flags, ' ') && str[0] != '-')
		REASSIGN(str, ft_strjoin(" ", str));
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
	char	*str;
	unsigned int		precision;

	str = va_arg(ap, char*);
	if (str == NULL)
		return (ft_strdup("(null)"));
	precision = ft_atoi(ph->precision);
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
