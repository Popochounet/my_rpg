/*
** EPITECH PROJECT, 2022
** my_putnbr_base.c
** File description:
** ->   puts an int according to a base
*/

#include <my.h>
#include "my_printf.h"


static wchar_t *u_my_wputnbr_base_impl
(uintmax_t n, const wchar_t *base, int base_n, wchar_t *buf)
{
    if (n < (uintmax_t)base_n) {
        buf = wstr_append(buf, base[n]);
    } else {
        buf = u_my_wputnbr_base_impl(n / base_n, base, base_n, buf);
        buf = u_my_wputnbr_base_impl(n % base_n, base, base_n, buf);
    }
    return buf;
}

wchar_t *u_my_wputnbr_base(uintmax_t n, const wchar_t *base)
{
    wchar_t *buffer = NULL;
    buffer = u_my_wputnbr_base_impl(n, base, my_wstrlen(base), buffer);
    return buffer;
}

wchar_t *my_wputnbr_base(intmax_t n, const wchar_t *base)
{
    wchar_t *buffer = NULL;
    const uintmax_t u_number = n < 0 ?
    (uintmax_t)(-(n + 1)) + 1 : (uintmax_t)n;

    if (n < 0) {
        buffer = wstr_append(buffer, '-');
    }
    return u_my_wputnbr_base_impl(u_number, base, my_wstrlen(base), buffer);
}
