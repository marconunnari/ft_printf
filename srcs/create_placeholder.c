/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_placeholder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 19:32:52 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/06 19:36:17 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_placeholder	*create_placeholder(const char **format)
{
	t_placeholder		ph;
	int					i;

	ph = init_placeholder();
	i = 0;
	while (i < 4)
	{
		get_flags(format, ph);
		get_width(format, ph);
		get_precision(format, ph);
		get_length(format, ph);
		i++;
	}
	while (ft_strchr(g_types
}
