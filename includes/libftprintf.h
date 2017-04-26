/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:46:32 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/26 19:05:37 by mnunnari         ###   ########.fr       */
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

int				ft_printf(const char *restrict format, ...);
t_placeholder	*init_placeholder();
int				process(const char *format, va_list ap);
t_placeholder	*create_placeholder(const char **format);
int				process_placeholder(t_placeholder *ph, va_list ap);

#endif
