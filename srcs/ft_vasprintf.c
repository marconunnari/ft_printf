#include "libftprintf.h"

int			ft_vasprintf(char **str, const char *format, va_list ap)
{
	char		*res;
	t_placeholder	*curr_ph;

	res = ft_strnew(0);
	while(*format)
	{
		if (*format == '%')
		{
			curr_ph = create_placeholder(&format);
			res = ft_strmerge(res, process_placeholder(curr_ph, ap));
		}
		res = ft_strappend(res, *format);
		format++;
	}
	*str = res;
	return (ft_strlen(res));
}
