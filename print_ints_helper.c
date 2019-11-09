#include "ft_printf.h"
//TODO написать функции. Переделать, когда будут флаги. Добавить счет выводимых в консоль символов в возвращаемое значение.
int				print_normal_int(t_format format, int value)
{
	if (format.width > format.precision)
	{
		while (format.width > format.precision && format.width > count_digits(value))
		{
			ft_putchar(' ');
			format.width--;
		}
	}
	while (format.precision-- > count_digits(value))
		ft_putchar('0');
	ft_putnbr(value);
	return (count_digits(value));
}

int				print_long_int(t_format format, long int value)
{
	if (format.width > format.precision)
	{
		while (format.width > format.precision && format.width > count_digits(value))
		{
			ft_putchar(' ');
			format.width--;
		}
	}
	while (format.precision-- > count_digits(value))
		ft_putchar('0');
	return (ft_putnbr_long_long(value, 0));
}

int				print_short_int(t_format format, short int value)
{
	if (format.width > format.precision)
	{
		while (format.width > format.precision && format.width > count_digits(value))
		{
			ft_putchar(' ');
			format.width--;
		}
	}
	while (format.precision-- > count_digits(value))
		ft_putchar('0');
	ft_putnbr(value);
	return (count_digits(value));
}

int				print_long_long_int(t_format format, long long int value)
{
	if (format.width > format.precision)
	{
		while (format.width > format.precision && format.width > count_digits(value))
		{
			ft_putchar(' ');
			format.width--;
		}
	}
	while (format.precision-- > count_digits(value))
		ft_putchar('0');
	return(ft_putnbr_long_long(value, 0));
}

int				print_signed_char_int(t_format format, char value)
{
	if (format.width > format.precision)
	{
		while (format.width > format.precision && format.width > count_digits(value))
		{
			ft_putchar(' ');
			format.width--;
		}
	}
	while (format.precision-- > count_digits(value))
		ft_putchar('0');
	ft_putnbr(value);
	return (count_digits(value));
}