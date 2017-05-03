#include "libftprintf.h"

char					*printchr(t_placeholder *ph, va_list ap)
{
	char	chr;
	char	*str;

	if (ft_strequ(ph->length, "l"))
		return (printwchr(ph, ap));
	chr = va_arg(ap, int);
	str = ft_strnew(1);
	if (chr == 0)
		chr = 1;
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

char					*printpercent(t_placeholder *ph, va_list ap)
{
	char	*str;

	(void)ph;
	(void)ap;
	str = ft_strnew(1);
	str[0] = '%';
	return (str);
}
