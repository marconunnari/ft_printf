#include "libftprintf.h"

char		*wchartostr(wchar_t wchr)
{
	char		*str;

	str = NULL;
	if (wchr < (1 << 7))
	{
		str = ft_strnew(1);
		str[0] = (unsigned char)(wchr);
	}
	else if (wchr < (1 << 11))
	{
		str = ft_strnew(2);
		str[0] = (unsigned char)((wchr >> 6) | 0xC0);
		str[1] = (unsigned char)((wchr & 0x3F) | 0x80);
	}
	else if (wchr < (1 << 16))
	{
		str = ft_strnew(3);
		str[0] = (unsigned char)(((wchr >> 12)) | 0xE0);
		str[1] = (unsigned char)(((wchr >> 6) & 0x3F) | 0x80);
		str[2] = (unsigned char)((wchr & 0x3F) | 0x80);
	}
	else
	{
		str = ft_strnew(4);
		str[0] = (unsigned char)(((wchr >> 18)) | 0xF0);
		str[1] = (unsigned char)(((wchr >> 12) & 0x3F) | 0x80);
		str[2] = (unsigned char)(((wchr >> 6) & 0x3F) | 0x80);
		str[3] = (unsigned char)((wchr & 0x3F) | 0x80);
	}
	return (str);
}

char					*printwchr(t_placeholder *ph, va_list ap)
{
	wchar_t		wchr;
	char		*str;

	(void)ph;
	wchr = va_arg(ap, wchar_t);
	str = wchartostr(wchr);
	return (str);
}

char					*wstrtostr(wchar_t *wstr, int len)
{
	char		*str;
	char		*tmp;
	int		i;

	i = 0;
	str = ft_strnew(0);
	while (*wstr && (i <= len))
	{
		tmp = wchartostr(*wstr);
		i += ft_strlen(tmp);
		if (i <= len)
			str = ft_strmerge(str, tmp);
		wstr++;
	}
	return (str);
}

char					*printwstr(t_placeholder *ph, va_list ap)
{
	wchar_t			*wstr;
	char			*str;
	unsigned int		precision;

	wstr = va_arg(ap, wchar_t*);
	if (wstr == NULL)
		wstr = L"(null)";
	precision = ft_strlen(ph->precision) != 0 ? ft_atoi(ph->precision) : 2147483647;
	str = wstrtostr(wstr, precision);
	return (str);
}
