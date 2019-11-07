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