#include "libftprintf.h"

char					*printuint(t_placeholder *ph, va_list ap)
{
	unsigned int		i;
	char				*str;

	(void)ph;
	i = va_arg(ap, unsigned int);
	str = ft_ulltoa_base(i, 10);
	return (ft_strdup(str));
}

char					*printint(t_placeholder *ph, va_list ap)
{
	int		i;
	char	*str;

	(void)ph;
	i = va_arg(ap, int);
	str = ft_lltoa(i);
	return (ft_strdup(str));
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
