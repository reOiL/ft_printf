/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:42:23 by jwebber           #+#    #+#             */
/*   Updated: 2019/10/26 16:42:24 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

/* Спецификаторы:
 * c
 * s
 * p
 * d
 * i
 * o
 * x
 * X
 * f
 */
typedef struct	s_format
{
	int			flags[5];	// 5 флагов (0,#,+,-, ), значение каждого элемента массива - 0 или 1. 
							// При нахождении флага после % соответсвующее значение установится в 1
							// (Но некоторые флаги несовместимы, с этим надо подумать.)
	int			width;		// Ширина поля
	int			precision;	// Точность. Мб при отсутсвии значений точности и ширины, можно их инициализировать как -1?
	int			modifier[4];// Модификаторы (l, h, ll, hh)(или все таки char[2]?)
	char		type;		// Тип преобразования.(или int)
	void		*value;		// Нужен ли нам в этой структуре указатель на выводимое значение?
}				t_format;

/*
 * Примерно план такой - двигаем указатель по данной строке и печатаем символы, при встрече 
 * % передаем указатель в функцию, которая будет возвращать инт - сдвиг указателя после 
 * печати сооветсвующего значения. (i += print_value(str[i], ...)). При невалидных значениях 
 * после % функция будет возвращать 0, что будет означать печать тех символов, что есть в 
 * строке
*/

//helper_numbers.c
int				count_digits(int value);

//print_numbers.c
void			print_int(t_format format, int value);

//get_format.c
int 			get_width(const char *str, int *i);
int 			get_precision(const char *str, int *i);
char 			get_type(const char *str);

//ft_printf.c
void			print_int(t_format format, int value);
int				ft_printf(const char *format, ...);

#endif //FILLIT_FT_PRINTF_H
