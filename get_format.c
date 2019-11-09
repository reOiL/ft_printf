#include "ft_printf.h"

unsigned int get_flags(const char *str, int *it)
{
	unsigned int res;

	res = 0;
	if (str == NULL || it == NULL)
		return (0);
	while (1)
	{
		if (*str == '-')
			res |= FLAG_MINUS;
		else if (*str == '+')
			res |= FLAG_PLUS;
		else if (*str == ' ')
			res |= FLAG_SPACE;
		else if (*str == '#')
			res |= FLAG_SHARP;
		else if (*str == '0')
			res |= FLAG_ZERO;
		else
			break;
		(*it)++;
		str++;
	}
	return (res);
}

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

	precision = -1;
	if (*str++ == '.')
	{
		(*i)++;
		while (ft_isdigit(*str))
		{
			precision = precision == -1 ? *str - '0' : *str - '0' * precision * 10;
			str++;
			(*i)++;
		}
	}
	return (precision);
}

int		get_modifier(const char *str, int *i)
{
	if (*str == 'l')
	{
		(*i)++;
		if (*(++str) == 'l')
		{
			(*i)++;
			return (MOD_LL);
		}
		return (MOD_L);
	}
	else if (*str == 'h')
	{
		(*i)++;
		if (*(++str) == 'h')
		{
			(*i)++;
			return (MOD_HH);
		}
		return (MOD_H);
	}
	/*
	else if (*str == 'L')
	{
		(*i)++;
		return (5);
	}
	*/
	return (0);
}