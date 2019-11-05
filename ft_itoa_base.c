/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:20:58 by exam              #+#    #+#             */
/*   Updated: 2019/07/19 16:03:26 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		calc_len(long long val, int base)
{
	if (val == 0)
		return (1);
	return calc_len(val / base, base) + 1;
}

char	cast_base(long long val)
{
	char c;

	c = '0';
	if (val >= 0 && val <= 9)
		c += val;
	else if (val >= 10 && val <= 16)
		c = (val - 10) + 'A';
	return (c);
}

void	itoa_2(char **array, long long val, int base, long long index)
{
	if (val / base != 0)
		itoa_2(array, val / base, base, index - 1);
	(*array)[index] = cast_base(val % base);
}

char	*ft_itoa_base(int value, int base)
{
	char *array;
	long long len;
	int is_minus;
	long long val2;

	if (base < 2 || base > 16)
	{
		array = ft_memalloc(2 * sizeof(char));
		array[0] = '0';
		return (array);
	}
	val2 = value;
	is_minus = 0;
	if (val2 < 0)
	{
		if (base == 10)
			is_minus = 1;
		val2 *= -1;
	}
	len = calc_len(val2, base) + (val2 == 0);
	array = ft_memalloc((len + is_minus) * sizeof(char));
	if (is_minus)
		array[0] = '-';
	itoa_2(&array, val2, base, len - (2 - is_minus));
	array[len - (1 - is_minus)] = '\0';
	return array;
}
