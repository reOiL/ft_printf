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

int        put_char_count(char c, int count)
{
    int i;

    i = 0;
    while (count > 0)
    {
        ft_putchar(c);
        i++;
        count--;
    }
    return (i);
}

void    to_lower(char *str)
{
    while (*str)
    {
        if (*str > 'A' && *str < 'Z')
            *str += 32;
        str++;
    }
}

int             put_nbr_base(t_integers val, t_format format, int base)
{
    char *tmp;
    size_t len;
    int     is_minus;
    char*    spec;

    is_minus = 0;
    spec = "\0";
    if (val.ll < 0 && (format.type == 'd' || format.type == 'i'))
    {
        is_minus += 1;
        val.ull = -val.ll;
    }
    tmp = ft_itoa_base(val.ull, base);
    if (format.type == 'x')
        to_lower(tmp);
    len = ft_strlen(tmp);
    if(is_minus)
        spec = "-";
    else if (format.flags & FLAG_SHARP && val.ull != 0)
        spec = "0x";
    else if (format.flags & FLAG_PLUS)
        spec = "+";
    else if(format.flags & FLAG_SPACE)
        spec = " ";
    if (spec[0])
        ft_putstr(spec);
    if (format.flags & FLAG_ZERO || format.precision > 0)
        len += put_char_count('0', format.precision - len);
    ft_putstr(tmp);
    ft_strdel(&tmp);
    return (len + ft_strlen(spec));
}