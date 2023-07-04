/*
** EPITECH PROJECT, 2022
** flag_p.c
** File description:
** ->   puts an address
*/

#include <stdlib.h>
#include <my.h>
#include "my_printf.h"

wchar_t *flag_p(void *ptr)
{
    wchar_t *address = my_wputnbr_base((long long)ptr, L"0123456789abcdef");
    wchar_t *str = wstr_append_str(my_wstrdup(L"0x"), address);
    free(address);
    return str;
}
