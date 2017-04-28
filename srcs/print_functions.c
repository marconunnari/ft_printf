#include "libftprintf.h"

char					*printuint(t_placeholder *ph, va_list ap)
{
	unsigned int		i;
	int					base;
	char				*str;

	(void)ph;
	i = va_arg(ap, unsigned int);
	base = 10;
	if (ph->type[0] == 'x' || ph->type[0] == 'X'
			|| ph->type[0] == 'p')
		base = 16;
	if (ph->type[0] == 'o')
		base = 8;
	str = ft_ulltoa_base(i, base);
	if (ph->type[0] == 'p')
		REASSIGN(str, ft_strjoin("0x", str));
	if (ft_strcont(ph->flags,'#'))
	{
		if (!ft_strequ(str, "0"))
		{
			if (ph->type[0] == 'x' || ph->type[0] == 'X')
				REASSIGN(str, ft_strjoin("0x", str));
			if (ph->type[0] == 'o'	)
				REASSIGN(str, ft_strjoin("0", str));
		}
	}
	if (ph->type[0] == 'X')
		str = ft_strtoupper(str);
	return (str);
}

char					*printint(t_placeholder *ph, va_list ap)
{
	int		i;
	char	*str;

	(void)ph;
	i = va_arg(ap, int);
	str = ft_lltoa(i);
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

	(void)ph;
	str = va_arg(ap, char*);
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
