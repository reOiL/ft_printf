#include "ft_printf.h"

int 	is_neg(long long val)
{
	return (val < 0);
}

int 	print_sign(t_integers *data, t_format *format)
{
	if ((*data).ll < 0)
	{
		ft_putchar('-');
		if (!(((*data).ll == MIN_LONG && (*format).modifier & MOD_L) \
		|| ((*data).ull == MIN_LLONG && (*format).modifier & MOD_LL)))
			(*data).ll = -(*data).ll;
		return (1);
	}
	else if ((*format).flags & FLAG_PLUS && (*data).ll >= 0)
	{
		ft_putchar('+');
		return (1);
	}
	else if ((*format).flags & FLAG_SPACE && (*data).ll >= 0)
	{
		ft_putchar(' ');

		return (1);
	}
	return (0);
}

int 	count_digits(long long int value, int base)
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

int 			count_digits_uns(unsigned long long value, int base)
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

int             put_nbr_base(t_format format, t_integers val, int base, int uns_sign)
{
	char 		*tmp;
	size_t 		len;

	len = 0;
	if (check_zero_number(format, val))
	{
		if (format.width)
			return (ft_putstr_size(ft_strdup(" "), 2));
		return (0);
	}
	if (uns_sign)
		tmp = ft_itoa_base_uns(val.ull, base);
	else
		{
		if (((format.flags & FLAG_PLUS && !(format.width > format.precision && (format.flags & FLAG_ZERO)))) || (val.ll < 0 && !(format.width > format.precision && (format.flags & FLAG_ZERO))) || format.flags & FLAG_MINUS)
			len += print_sign(&val, &format);
		tmp = ft_itoa_base(val.ll, base);
	}
	len += ft_strlen(tmp);
	while (format.precision-- > (int)ft_strlen(tmp))
	{
		len++;
		ft_putchar('0');
	}
	ft_putstr(format.type == 'x' ? ft_tolower_str(tmp) : tmp);
	ft_strdel(&tmp);
	return (len);
}