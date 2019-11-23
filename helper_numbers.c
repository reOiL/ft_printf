/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:43:19 by eblackbu          #+#    #+#             */
/*   Updated: 2019/11/16 14:44:15 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_neg(long long val)
{
	return (val < 0);
}

int		print_sign(t_integers *data, t_format format)
{
	if ((*data).ll < 0)
	{
		ft_putchar('-');
		if (!(((*data).ll == MIN_LONG && format.modifier & MOD_L) \
		|| ((*data).ull == MIN_LLONG && format.modifier & MOD_LL)))
			(*data).ll = -(*data).ll;
		return (1);
	}
	else if (format.flags & FLAG_PLUS && (*data).ll >= 0)
	{
		ft_putchar('+');
		return (1);
	}
	else if (format.flags & FLAG_SPACE && (*data).ll >= 0)
	{
		ft_putchar(' ');
		return (1);
	}
	return (0);
}

int		count_digits(long long int value, int base)
{
	int		i;

	i = 1;
	if (value < 0)
	{
		i++;
		value *= -1;
	}
	while (value / base)
	{
		i++;
		value /= base;
	}
	return (i);
}

int		count_digits_uns(unsigned long long value, int base)
{
	int		i;

	i = 1;
	while (value / base)
	{
		i++;
		value /= base;
	}
	return (i);
}

int		put_nbr_base(t_format format, t_integers val, int base, int uns_sign)
{
	char	*tmp;
	size_t	len;

	if (check_zero_number(format, val))
	{
		if (format.width)
			return (ft_putstr_size(ft_strdup(" "), 2));
		return (0);
	}
	if (uns_sign)
		tmp = ft_itoa_base_uns(val.ull, base);
	else {
		if (val.ll < 0)
			ft_putchar('-');
		tmp = ft_itoa_base(val.ll, base);
	}
	len = ft_strlen(tmp);
	while (format.precision-- > count_digits_uns(val.ull, base))
	{
		len++;
		ft_putchar('0');
	}
	ft_putstr(format.type == 'x' ? ft_tolower_str(tmp) : tmp);
	ft_strdel(&tmp);
	return (len);
}
