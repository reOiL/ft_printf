#include "ft_printf.h"

char 	get_type(const char *str)
{
	if (*str == 'c' || *str == 's' || *str == 'p')
		return (*str);
	else if (*str == 'd' || *str == 'i' || *str == 'o')
		return (*str);
	else if (*str == 'u' || *str == 'x' || *str == 'X')
		return (*str);
	else if (*str == 'f')
		return (*str);
	else
		return (0);
}

int 	get_width(const char *str, int *i)
{
	int 	width;

	width = 0;
	while (ft_isdigit(*str))
	{
		width = *str++ - '0' + width * 10;
		(*i)++;
	}
	return (width);
}

int 	get_precision(const char *str, int *i)
{
	int 	precision;

	precision = 0;
	if (*str++ == '.')
	{
		(*i)++;
		while (ft_isdigit(*str))
		{
			precision = *str++ - '0' + precision * 10;
			(*i)++;
		}
	}
	return (precision);
}