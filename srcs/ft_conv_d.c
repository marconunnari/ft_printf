#include "libftprintf.h"

void		conv_d(t_placeholder *ph, va_list ap)
{
	int	d;

	(void)ph;
	d = va_arg(ap, int);
	ft_putstr(ft_imaxtoa(d));
}
