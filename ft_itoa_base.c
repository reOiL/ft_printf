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

int		calc_len(unsigned long long val, int base)
{
	if (val == 0)
		return (1);
	return calc_len(val / base, base) + 1;
}

char	cast_base(unsigned short val)
{
	char c;

	c = '0';
	if (val >= 0 && val <= 9)
		c += val;
	else if (val >= 10 && val <= 16)
		c = (val - 10) + 'A';
	return (c);
}

void	itoa_2(char **array, unsigned long long val, int base, size_t index)
{
	if (val / base != 0)
		itoa_2(array, val / base, base, index - 1);
	(*array)[index] = cast_base(val % base);
}

char	*ft_itoa_base(unsigned long long value, int base)
{
	char *array;
	long long len;

	if (base < 2 || base > 16 || value == 0)
	{
		array = ft_strnew(1);
		array[0] = '0';
		return (array);
	}
	len = calc_len(value, base) - 1;
	array = ft_strnew(len);
	itoa_2(&array, value, base, len - 1);
	return array;
}

int             put_nbr_base(t_integers val, t_format format, int base)
{
    char *tmp;
    size_t len;
    int     is_minus;

    is_minus = 0;
    if (val.ll < 0 && format.type != 'u')
    {
        is_minus += 1;
        val.ull = -val.ll;
    }
    tmp = ft_itoa_base(val.ull, base);
    len = ft_strlen(tmp) + is_minus;
    if(is_minus)
        ft_putchar('-');
    ft_putstr(tmp);
    ft_strdel(&tmp);
    return (len);
}