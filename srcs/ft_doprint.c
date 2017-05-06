/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 18:59:02 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/06 19:32:43 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			do_conv(const char **format, va_list ap)
{
	char		*formatptr;

	(void)ap;
	formatptr = *format + 1;
}

void			do_print(const char *format, va_list ap)
{
	while (*format)
	{
		if (*format == '%')
			do_conv(&format, ap);
		else
			ft_putchar(*format);
		format++;
	}
}
