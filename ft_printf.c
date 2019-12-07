/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:42:23 by jwebber           #+#    #+#             */
/*   Updated: 2019/10/26 16:42:24 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_value(t_format format, va_list args)
{
	if (format.type == '%')
		return (print_percent(format));
	if (format.type == 'c')
		return (print_char(format, args));
	else if (format.type == 's')
		return (print_string(format, args));
	else if (format.type == 'p')
		return (print_address(format, args));
	else if (format.type == 'd' || format.type == 'i')
		return (print_int(format, args));
	else if (format.type == 'o' || format.type == 'u' ||\
			format.type == 'x' || format.type == 'X')
		return(print_int_unsigned(format, args));
	else if (format.type == 'f')
		return(print_float(format, args));
	return (0);
}

int			get_format(va_list args, const char *str, int *printed_count)
{
	int			i;
	t_format	format;

	i = 1;
	format.flags = get_flags(&str[i], &i);
	format.width = get_width(&str[i], &i, args, &format);
	format.precision = get_precision(&str[i], &i, args);
	format.modifier = get_modifier(&str[i], &i);
	format.type = get_type(&str[i]);
	if (format.type)
	{
		*printed_count += print_value(format, args);
		return (i + 1);
	}
	return (0);
}

int			ft_printf(const char *str, ...)
{
	int		i;
	int		offset;
	int		printed_count;
	va_list	args;

	i = 0;
	printed_count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			offset = get_format(args, &str[i], &printed_count);
			if (offset)
				i += offset;
			else if (str[++i])
			{
				ft_putchar(str[i]);
				printed_count++;
			}
		}
		else
		{
			ft_putchar(str[i++]);
			printed_count++;
		}
	}
	va_end(args);
	return (printed_count);
}
