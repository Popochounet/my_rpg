/*
** EPITECH PROJECT, 2022
** my_itoa_base.c
** File description:
** ->   converts an int into char* according to a base
*/

#include <my.h>


static char *my_utoa_base_impl
(uintmax_t n, const char *base, int base_n, char *buf)
{
    if (n < (uintmax_t)base_n) {
        buf = str_append(buf, base[n]);
    } else {
        buf = my_utoa_base_impl(n / base_n, base, base_n, buf);
        buf = my_utoa_base_impl(n % base_n, base, base_n, buf);
    }
    return buf;
}

char *my_utoa_base(uintmax_t n, const char *base)
{
    char *buffer = NULL;
    buffer = my_utoa_base_impl(n, base, my_strlen(base), buffer);
    return buffer;
}

char *my_itoa_base(intmax_t n, const char *base)
{
    char *buffer = NULL;
    const uintmax_t u_number = n < 0 ?
    (uintmax_t)(-(n + 1)) + 1 : (uintmax_t)n;

    if (n < 0) {
        buffer = str_append(buffer, '-');
    }
    return my_utoa_base_impl(u_number, base, my_strlen(base), buffer);
}

char *my_utoa(uintmax_t n)
{
    char *buffer = NULL;

    return my_utoa_base_impl(n, "0123456789", 10, buffer);
}

char *my_itoa(intmax_t n)
{
    char *buffer = NULL;
    const uintmax_t u_number = n < 0 ? (uintmax_t)(-(n + 1)) + 1 : (uintmax_t)n;

    if (n < 0) {
        buffer = str_append(buffer, '-');
    }
    return my_utoa_base_impl(u_number, "0123456789", 10, buffer);
}
