/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_numbers2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:44:23 by eblackbu          #+#    #+#             */
/*   Updated: 2019/11/16 14:45:24 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_zero_number(t_format format, t_integers val)
{
	if (!format.precision && val.ull == 0 && \
		(format.type == 'x' || format.type == 'X' \
		|| (format.type == 'o' && !(format.flags & FLAG_SHARP)) \
		|| format.type == 'u' || format.type == 'p'))
		return (1);
	if (!format.precision && val.ll == 0 && \
		(format.type == 'd' || format.type == 'i'))
		return (1);
	return (0);
}

/*
void		get_width_pres(t_integers data, t_format format, int *count)
{
	if (format.width > format.precision)
	{
		while (format.width > ft_max(format.precision + sign, \
	count_digits(data.ll, 10) + (format.flags & FLAG_PLUS || \
		format.flags & FLAG_SPACE || ((format.flags & FLAG_ZERO) && minus))))
		{
			ft_putchar((format.flags & FLAG_ZERO) && format.precision < 0 ? '0' : ' ');
			format.width--;
			count++;
		}
	}
}
 */