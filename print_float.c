//
// Created by reoil on 07.11.2019.
//

#include "ft_printf.h"
#include <stdio.h>

char	*float_leading(double d)
{
	return (ft_itoa_base((long long)d, 10));
}

char 	*float_fraction(double d, int *precision)
{
	char	*ret;
	double	accur;
	int 	i;

	*precision = *precision < 0 ? 6 : *precision;
	if (!(ret = ft_strnew(*precision + (precision != 0))))
		return (NULL);
	if (*precision == 0)
		return (ret);
	d = d < 0 ? -d : d;
	accur = 5;
	i = 0;
	while (i < *precision + 1)
	{
		accur /= 10;
		i++;
	}
	ret[i = 0] = '.';
	d += accur;
	while (i < *precision)
	{
		d *= 10;
		ret[++i] = ('0' + (unsigned long long)d % 10);
	}
	return (ret);
}

size_t 	putchar_count(char c, size_t count)
{
	char	*p;

	if (!(p = ft_strnew(count)))
		return (0);
	ft_memset(p, c, count);
	ft_putstr(p);
	ft_strdel(&p);
	return (count);
}

int				print_float(t_format format, va_list args)
{
	double	d;
	char	*leading;
	char 	*fraction;
	int 	size;

	d  = va_arg(args, double);
	size = 0;
	if(!(leading = float_leading(d)))
		return (0);
	if (!(fraction = float_fraction(d, &format.precision)))
	{
		ft_strdel(&leading);
		return (0);
	}
	size += ft_strlen(leading) + ft_strlen(fraction);
	if (format.flags & FLAG_PLUS)
	{
		size++;
		ft_putchar('+');
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