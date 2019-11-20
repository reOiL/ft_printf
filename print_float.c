/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:15:51 by jwebber           #+#    #+#             */
/*   Updated: 2019/11/20 15:49:55 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "floating.h"

char			*float_fraction(long double d, int *precision)
{
	char	*ret;
	double	accur;
	int		i;

	*precision = *precision < 0 ? 6 : *precision;
	if (*precision == 0 || ((long long)d == 0 && *precision == 0))
		return (ft_strdup(""));
	if (!(ret = ft_strnew(*precision + (precision != 0))))
		return (NULL);
	d = (d < 0 ? -d : d);
	d -= (long long)d;
	accur = 5;
	i = 0;
	while (i++ < *precision + 1)
		accur /= 10;
	i = 0;
	ret[0] = '.';
	d += accur;
	while (i < *precision)
	{
		d *= 10;
		ret[++i] = ('0' + (unsigned long long)d % 10);
	}
	return (ret);
}

size_t			putchar_count(char c, size_t count)
{
	char	*p;

	if (!(p = ft_strnew(count)))
		return (0);
	ft_memset(p, c, count);
	ft_putstr(p);
	ft_strdel(&p);
	return (count);
}

int				print_float2(t_format format, char *leading, char *fraction,
		long double d)
{
	int	size;

	size = ft_strlen(leading) + ft_strlen(fraction);
	if (format.flags & FLAG_PLUS && d >= 0)
	{
		size++;
		ft_putchar('+');
	}
	if ((long long)d == 0 && d < 0)
	{
		size++;
		ft_putchar('-');
	}
	if (format.width > 0 && format.width > size && !(format.flags & FLAG_MINUS))
		size += putchar_count(' ', format.width - size);
	ft_putstr(leading);
	ft_putstr(fraction);
	if (format.flags & FLAG_MINUS && format.width > 0 && format.width > size)
		size += putchar_count(' ', format.width - size);
	ft_strdel(&leading);
	ft_strdel(&fraction);
	return (size);
}

int				handle_spec(char **leading, char **fraction, long double d)
{
	if (!(*fraction = ft_strdup("")))
		return (-1);
	if (d == PINF && !(*leading = ft_strdup("inf")))
	{
		ft_strdel(fraction);
		return (-1);
	}
	if (d == MINF && !(*leading = ft_strdup("-inf")))
	{
		ft_strdel(fraction);
		return (-1);
	}
	if (d != d && !(*leading = ft_strdup("nan")))
	{
		ft_strdel(fraction);
		return (-1);
	}
	return (1);
}

int				print_float(t_format format, va_list args)
{
	long double	d;
	char		*leading;
	char		*fraction;

	if (format.modifier & MOD_LD)
		d = va_arg(args, long double);
	else
		d = va_arg(args, double);
	if (d == PINF || d == MINF || d != d)
	{
		if (handle_spec(&leading, &fraction, d) < 0)
			return (0);
	}
	else
	{
		if (!(leading = ft_itoa_base((long long)d, 10)))
			return (0);
		if (!(fraction = float_fraction(d, &format.precision)))
		{
			ft_strdel(&leading);
			return (0);
		}
	}
	return (print_float2(format, leading, fraction, d));
}
