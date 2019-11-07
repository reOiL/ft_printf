//
// Created by reoil on 07.11.2019.
//
#include "ft_printf.h"

unsigned int get_modifier(const char *str, int *it)
{
    unsigned int res;

    res = 0;
    if (str == NULL || it == NULL)
        return (0);
    while (1)
    {
        if (*str == 'l')
            res |= MOD_L;
        else if (ft_strcmp(str, "ll")  == 0)
            res |= MOD_LL;
        else if (ft_strcmp(str, "h")  == 0)
            res |= MOD_H;
        else if (ft_strcmp(str, "hh")  == 0)
            res |= MOD_HH;
        else
            break;
        (*it)++;
        str++;
    }
    return (res);
}
