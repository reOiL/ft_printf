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