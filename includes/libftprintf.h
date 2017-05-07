/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:46:32 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/06 19:41:09 by mnunnari         ###   ########.fr       */
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

int				ft_printf(const char *restrict format, ...);

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putchar(char c);
void			ft_putstr(const char *str);

void			do_print(const char *format, va_list ap);
void			do_conv(const char **format, va_list ap);

t_placeholder	*createph(const char **format);
void			freeph(t_placeholder *ph);

void			get_parameter(const char **format, t_placeholder *ph);
void			get_flags(const char **format, t_placeholder *ph);
void			get_width(const char **format, t_placeholder *ph);
void			get_precision(const char **format, t_placeholder *ph);
void			get_length(const char **format, t_placeholder *ph);
void			get_type(const char **format, t_placeholder *ph);

void		conv_s(t_placeholder *ph, va_list ap);
void		conv_d(t_placeholder *ph, va_list ap);

#endif
