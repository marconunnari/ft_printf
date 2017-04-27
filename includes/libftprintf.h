/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:46:32 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/27 19:38:39 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

typedef struct	s_placeholder
{
	char		*flags;
	char		*width;
	char		*precision;
	char		*length;
	char		*type;
}				t_placeholder;

int		ft_vasprintf(char **ret, const char *format, va_list ap);
int				ft_printf(const char *restrict format, ...);
t_placeholder	*init_placeholder();
void			free_placeholder(t_placeholder	*ph);
void			process(char **ret, const char *format, va_list ap);
t_placeholder	*create_placeholder(const char **format);
char			*process_placeholder(t_placeholder *ph, va_list ap);

#endif
