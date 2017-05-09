#include "libftprintf.h"

void	numprec(t_placeholder *ph, char **str)
{
	char		*fix;
	int			strlen;

	strlen = ft_strlen(*str);
	IFRETURNVOID(ph->precision < strlen);
	fix = ft_strnew(ph->precision - strlen);
	ft_memset(fix, '0', ph->precision - strlen);
	*str = ft_strmerge(fix, *str);
}
