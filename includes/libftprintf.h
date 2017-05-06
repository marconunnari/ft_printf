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

static char		g_flags = "#0-+"
static char		g_lengths = "hljz";
static char		g_types = "sSpdDioOuUxXcC";

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

#endif
