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
	//TODO после написания всех функций get_*, придумать, как все это выводить.
	//TODO Все еще проблема с получением количества выводимых символов. Хз, получится ли каждый раз передавать адрес printed_count //upd. попробую возвращать на этом этапе количество печатаемых символов
	// Разобраться с сhar и string, как самым простым
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
		return (print_int_unsigned(format, args));
	/*	
	else if (format.type == 'f')
		return(print_float(format, args));
	*/
}

// get_format - получим все данные о том, как нужно печатать, после передадим это все в print_value
int			get_format(va_list args, const char *str, int *printed_count)
{
	int 		i;
	t_format	format;

	i = 1;
	format.flags = get_flags(&str[i], &i);
	// Передадим значение i по адресу,
	// чтобы мы могли его изменить прямо в функции
	// (получить флаги и сдвинуть поинтер)

	format.width = get_width(&str[i], &i);
	format.precision = get_precision(&str[i], &i);
	format.modifier = get_modifier(&str[i], &i);
	format.type = get_type(&str[i]);

	//Нужна какая то проверка, пока нет идей кроме как возвращать
	//странные значение в параметры format, а потом в функции check_value их проверять,
	//прежде чем отправлять печатать

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
	int		printed_count; // Подсчет символов, сколько в итоге напечатает printf, чтобы вернуть
	va_list	args;

	i = 0;
	printed_count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			offset = get_format(args, &str[i], &printed_count);
			if (offset)//Если у нас get_format вернет 0, значит что то не так со спецификаторами
				i += offset;
			else
			{
				ft_putchar(str[i++]);
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
