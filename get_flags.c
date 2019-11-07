//
// Created by reoil on 07.11.2019.
//

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