/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** my_real_printf
*/

#include <stdlib.h>
#include <my.h>
#include "my_printf.h"

int my_vprintf(const char *restrict format, va_list args)
{
    wchar_t *wformat = str_to_wstr(format);
    const int return_code = my_wvprintf(wformat, args);

    free(wformat);
    return return_code;
}

int my_printf(const char *restrict format, ...)
{
    va_list args;
    int return_code = 0;

    va_start(args, format);
    return_code = my_vprintf(format, args);
    va_end(args);
    return return_code;
}
