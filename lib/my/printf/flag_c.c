/*
** EPITECH PROJECT, 2022
** flag_c.c
** File description:
** ->   puts floating-point numbers
*/

#include <unistd.h>
#include <wchar.h>
#include <my.h>

wchar_t *flag_c(int c)
{
    wchar_t *str = my_wcalloc(2);
    str[0] = c;
    return str;
}

wchar_t *wflag_c(wint_t c)
{
    wchar_t *str = my_wcalloc(2);
    str[0] = c;
    return str;
}
