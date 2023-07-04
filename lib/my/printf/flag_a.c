/*
** EPITECH PROJECT, 2022
** flag_a.c
** File description:
** ->   flag %a -> writes a float in hexadecimal notation
*/

#include <stdlib.h>
#include <my.h>
#include <my_macros.h>
#include "my_printf.h"
#include "flag_a.h"

static wchar_t *remove_trailing_zeros(wchar_t *str, int has_hastag)
{
    size_t end_index = my_wstrlen(str) - 1;

    while (str[end_index] == '0') {
        str = wstr_pop(str, end_index--);
    }
    if (str[end_index] == '.' && !has_hastag) {
        free(str);
        str = NULL;
    }
    return str;
}

static wchar_t *hex_decimals
(long double n, int decimals, int has_hastag, int lower)
{
    unsigned short digit = 0;
    const wchar_t *base = lower ? L"0123456789abcdef" : L"0123456789ABCDEF";
    wchar_t *str = my_wstrdup(L".");

    while (decimals--) {
        digit = n * 16.L;
        n = n * 16.L - digit;
        str = wstr_append_str(str, u_my_wputnbr_base(digit, base));
    }
    return remove_trailing_zeros(str, has_hastag);
}

static wchar_t *append_exponent(wchar_t *str, short exponent, int lower)
{
    str = wstr_append(str, lower ? 'p' : 'P');
    if (exponent < 0) {
        str = wstr_append(str, '-');
        exponent = -exponent;
    } else {
        str = wstr_append(str, '+');
    }
    return wstr_append_str(str, my_wputnbr_base(exponent, L"0123456789"));
}

wchar_t *flag_a_impl(long double n, int decimals, int lower, int has_hashtag)
{
    const short exponent = get_exp2(n);
    wchar_t *str = lower ? my_wstrdup(L"0x") : my_wstrdup(L"0X");
    long double power2 = 0.L;
    int bigger_than_exponent = 0;

    if (n < 0.L) {
        str = my_wstrdup(L"-");
        n = -n;
    }
    power2 = pow2(exponent);
    bigger_than_exponent = n >= power2;
    str = wstr_append(str, '0' + bigger_than_exponent);
    n = n / power2 - bigger_than_exponent;
    str = wstr_append_str(str, hex_decimals(n, decimals, has_hashtag, lower));
    return append_exponent(str, exponent, lower);
}

wchar_t *flag_a(long double n, int decimals, int lower, int has_hashtag)
{
    if (my_isnan(n)) {
        return lower ? my_wstrdup(L"-nan") : my_wstrdup(L"-NAN");
    }
    if (my_isinf(n)) {
        if (n < 0) {
            return lower ? my_wstrdup(L"-inf") : my_wstrdup(L"-INF");
        } else {
            return lower ? my_wstrdup(L"inf") : my_wstrdup(L"INF");
        }
    }
    return flag_a_impl(n, decimals, lower, has_hashtag);
}
