/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:46:32 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/19 14:46:36 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

typedef struct	s_placeholder
{
	int			parameter;
	char		*flags;
	int			width;
	int			precision;
	char		*length;
	char		type;
}				t_placeholder;

typedef void	(*t_conv)(t_placeholder*, va_list);

typedef struct	s_typeconv
{
	char			type;
	t_conv			conv;
}				t_typeconv;

int				ft_printf(const char *restrict format, ...);

void			ft_printf_putchar(char c);
void			ft_printf_putstr(const char *str);
void			ft_printf_putwchar(wchar_t wchr);
void			ft_printf_putwstr(const wchar_t *wstr);

void			do_print(const char *format, va_list ap);
void			do_conv(const char **format, va_list ap);

t_placeholder	*createph(const char **format, va_list ap);
void			freeph(t_placeholder *ph);

void			get_parameter(const char **format, t_placeholder *ph);
void			get_flags(const char **format, t_placeholder *ph);
void			get_width(const char **format, t_placeholder *ph, va_list ap);
void			get_precision(const char **format, t_placeholder *ph,
							va_list ap);
void			get_length(const char **format, t_placeholder *ph);
void			get_type(const char **format, t_placeholder *ph);

void			conv_s(t_placeholder *ph, va_list ap);
void			conv_d(t_placeholder *ph, va_list ap);
void			conv_ws(t_placeholder *ph, va_list ap);
void			conv_c(t_placeholder *ph, va_list ap);
void			conv_pc(t_placeholder *ph, va_list ap);
void			conv_wc(t_placeholder *ph, va_list ap);
void			conv_ubase(t_placeholder *ph, va_list ap, int base);
void			conv_u(t_placeholder *ph, va_list ap);
void			conv_x(t_placeholder *ph, va_list ap);
void			conv_o(t_placeholder *ph, va_list ap);
void			conv_b(t_placeholder *ph, va_list ap);

void			width(t_placeholder *ph, char **str);
void			numprec(t_placeholder *ph, char **str, int is_zero);

char			*wchartostr(wchar_t wchr);

#endif
