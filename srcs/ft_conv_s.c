#include "libftprintf.h"

void		conv_s(t_placeholder *ph, va_list ap)
{
	char	*str;

	(void)ph;
	str = va_arg(ap, char*);
	ft_putstr(str);
}
