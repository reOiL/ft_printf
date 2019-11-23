/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ints_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:48:40 by eblackbu          #+#    #+#             */
/*   Updated: 2019/11/16 14:49:56 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_reverse_int(t_integers data, t_format format, int count)
{
	int		sign;

	sign = is_neg(data.ll) || (format.flags & FLAG_PLUS);
	count += print_sign(&data, format);
	count += put_nbr_base(format, data, 10, 0);
	if (format.width > format.precision)
	{
		while (format.width > ft_max(format.precision, \
					count_digits(data.ll, 10)) + sign)
		{
			ft_putchar(' ');
			format.width--;
			count++;
		}
	}
	return (count);
}

int		print_modified_int(t_integers data, t_format format)
{
	int		count;
	int		sign;
	int		minus;

	count = 0;
	minus = is_neg(data.ll);
	sign = (is_neg(data.ll) || format.flags & FLAG_PLUS \
			|| format.flags & FLAG_SPACE);
	if (format.flags & FLAG_MINUS)
		return (print_reverse_int(data, format, count));
	count += (format.flags & FLAG_ZERO) ? print_sign(&data, format) : 0;
	if (format.width > format.precision)
	{
		while (format.width > ft_max(format.precision + sign, \
	count_digits(data.ll, 10) + (format.flags & FLAG_PLUS || \
		format.flags & FLAG_SPACE || ((format.flags & FLAG_ZERO) && minus))))
		{
			ft_putchar((format.flags & FLAG_ZERO) && \
					format.precision < 0 ? '0' : ' ');
			format.width--;
			count++;
		}
	}
	count += !(format.flags & FLAG_ZERO) ? print_sign(&data, format) : 0;
	return (count + put_nbr_base(format, data, 10, 0));
}

int		print_int(t_format format, va_list args)
{
	t_integers	data;

	if (format.modifier & MOD_H)
		data.ll = (short)va_arg(args, int);
	else if (format.modifier & MOD_HH)
		data.ll = (signed char)va_arg(args, int);
	else if (format.modifier & MOD_L)
		data.ll = (long)va_arg(args, long);
	else if (format.modifier & MOD_LL)
		data.ll = (long long)va_arg(args, long long);
	else
		data.ll = (int)va_arg(args, int);
	return (print_modified_int(data, format));
}
