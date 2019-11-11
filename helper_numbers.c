#include "ft_printf.h"

//TODO Возможно нужен еще подсчет для 16 и 8

int 	is_neg(long long val)
{
	return (val < 0);
}

int 	print_sign(t_integers *data, t_format format)
{
	if ((*data).ll < 0)
	{
		ft_putchar('-');
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

int             put_nbr_base(t_integers val, int base, int uns_sign)
{
	char 		*tmp;
	size_t 		len;

	if (uns_sign)
		tmp = ft_itoa_base_uns(val.ull, base);
	else
		tmp = ft_itoa_base(val.ll, base);
	len = ft_strlen(tmp);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	return (len);
}