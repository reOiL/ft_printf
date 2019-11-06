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



//
void		print_value(t_format format, va_list args)
{
	//TODO после написания всех функций get_*, придумать, как все это выводить
	if (format.type == 'c')
		ft_putchar(va_arg(args, int));
	else if (format.type == 's')
		ft_putstr(va_arg(args, char*));
}

// get_format - получим все данные о том, как нужно печатать, после передадим это все в print_value
int			get_format(va_list args, const char *str)
{
	int 		i;
	t_format	format;

	i = 1;
	// format.flags = get_flags(&str[i], &i);
	// Передадим значение i по адресу,
	// чтобы мы могли его изменить прямо в функции
	// (получить флаги и сдвинуть поинтер)

	// format.width = get_width(&str[i], *i);
	// format.precision = get_precision(&str[i], *i);
	// format.modifier = get_modifier(&str[i], *i);
	format.type = get_type(&str[i++]);

	//Нужна какая то проверка, пока нет идей кроме как возвращать
	//странные значение в параметры format, а потом в функции check_value их проверять,
	//прежде чем отправлять печатать

	//if (check_value(format))
	//{
		print_value(format, args);
		return (i);
	//}
	//else
	//	return (0);
}

int			ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			i += get_format(args, &str[i]);
		else
			ft_putchar(str[i++]);
	}
	va_end(args);
	return (0);
}