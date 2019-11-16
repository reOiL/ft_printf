#include "ft_printf.h"

int 		ft_putstr_size(char *str, int precision)
{
	int 	i;
	int 	length;

	i = 0;
	length = 0;
	while (str[i] && precision--)
	{
		ft_putchar(str[i++]);
		length++;
	}
	free(str);
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

int 			print_minus_string(t_format format, char *str, long long length)
{
	length = ft_putstr_size(str, format.precision);
	while (format.width > length++)
		ft_putchar(' ');
	length--;
	return (length > format.width ? length : format.width);
}

int				print_string(t_format format, va_list args)
{
	int 	length;
	char 	*str;
	int 	i;

	i = 0;
	if (!(str = ft_strdup(va_arg(args, char*))))
		return (ft_putstr_size(ft_strdup("(null)"), 6));
	length = format.precision < (int)ft_strlen(str) && format.precision != -1 \
 ? format.precision : (int)ft_strlen(str);
	if (format.flags & FLAG_MINUS)
		return (print_minus_string(format, str, length));
	while (format.width > length++)
		ft_putchar(' ');
	if (format.precision > format.width && format.precision < (int)ft_strlen(str))
	{
		while (format.precision > (int) ft_strlen(str) + i++)
			ft_putchar(' ');
	}
	length = ft_putstr_size(str, format.precision);
	return ((int)(length > format.width ? length : format.width));
}
