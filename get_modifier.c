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
    if (ft_strcmp(str, "ll")  == 0)
    {
        res = MOD_LL;
        (*it) += 2;
    }
    else if (ft_strcmp(str, "l")  == 0)
    {
        res = MOD_L;
        (*it) += 1;
    }
    else if (ft_strcmp(str, "h")  == 0)
    {
        res = MOD_H;
        (*it) += 1;
    }
    else if (ft_strcmp(str, "hh")  == 0)
    {
        res = MOD_HH;
        (*it) += 2;
    }
    return (res);
}
