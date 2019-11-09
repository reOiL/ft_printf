#include "ft_printf.h"

int 		ft_putstr_size(char *str, int precision)
{
	int length;

	length = 0;
	while (*str && precision--)
	{
		ft_putchar(*str);
		length++;
		str++;
	}
	return (length);
}

int			print_char(t_format format, va_list args)
{
	int 	width;

	width = format.width;
	if (format.flags & FLAG_MINUS)
	{
		ft_putchar((char)va_arg(args, int));
		while (width-- > 1)
			ft_putchar(' ');
	}
	else
	{
		while (width-- > 1)
			ft_putchar(' ');
		ft_putchar((char)va_arg(args, int));
	}
	return (format.width ? format.width : 1);
}

int				print_string(t_format format, va_list args)
{
	long long 	length;
	int			width;
	char 		*str;

	width = format.width;
	str = ft_strdup(va_arg(args, char*));
	if (format.flags & FLAG_MINUS)
	{
		length = ft_putstr_size(str, format.precision);
		while (width-- > length)
			ft_putchar(' ');
	}
	else
	{
		length = (int)ft_strlen(str) < format.precision ? format.precision : ft_strlen(str);
		while (width-- > length)
			ft_putchar(' ');
		length = ft_putstr_size(str, format.precision);
	}
	free(str);
	return ((int)(length > format.width ? length : format.width));
}

//TODO atoi_base16 добавить (и формат x X) Аналогично с сhar, применяется только флаг '-'
int 		print_address(t_format format, va_list args)
{
	long long unsigned n;

	/*
	ft_putstr("0x");
	n = va_arg(args, long long unsigned);
	if (n / 16 != 0)
		ft_putnbr_long_long(n / 10, 0);
	ft_putchar('0' + n % 10);
	 */
}