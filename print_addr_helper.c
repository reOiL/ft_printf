#include "ft_printf.h"

long long	ft_max(long long a, long long b)
{
	return (a > b ? a : b);
}

char 		*str_tolower(char *str)
{
	int 	i;

	i = -1;
	while (str[++i])
		str[i] = (char)ft_tolower(str[i]);
	return (str);
}

char 		*get_addr_precision(char *num, int precision)
{
	int 	i;
	char	*new_num;

	i = 2;
	new_num = precision > 0 ? ft_strnew(precision) : ft_strnew(ft_strlen(num));
	new_num = ft_strcpy(new_num, "0x");
	while (precision-- > (int)(ft_strlen(num)))
		new_num[i++] = '0';
	new_num = ft_strcat(new_num, num);
	free(num);
	return (new_num);
}

int 		print_address(t_format format, va_list args)
{
	int 		length;
	int 		width;
	t_integers	n;
	char 		*num;

	width = format.width;
	n.ull = va_arg(args, unsigned long long);
	num = ft_itoa_base(n, 16);
	if (format.flags & FLAG_MINUS)
	{
		num = get_addr_precision(str_tolower(num), format.precision);
		length = ft_putstr_size(num, ft_strlen(num));
		while (width-- > length + 2)
			ft_putchar(' ');
	}
	else
	{
		num = get_addr_precision(str_tolower(num), format.precision);
		while (width-- > ft_max(ft_strlen(num), format.precision + 2))
			ft_putchar(' ');
		length = ft_putstr_size(num, ft_strlen(num));
	}
	return ((int)(length > format.width ? length : format.width));
}