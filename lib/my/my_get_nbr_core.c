/*
** EPITECH PROJECT, 2022
** my_getnbr_core.c
** File description:
** ->   core functions for get_nbr.c
** ->   allowed function : my_putchar
*/

#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <my.h>

bool is_char_valid_in_nbr(char c)
{
    return (c >= '0' && c <= '9') || (c == '-' || c == '+');
}

size_t my_nbr_strlen(const char *str)
{
    char *const nbr_end = str_find_not_pred((char*)str, is_char_valid_in_nbr);

    if (!str) {
        return 0;
    } else if (str && !nbr_end) {
        return my_strlen(str);
    }
    return nbr_end - str;
}

static unsigned max_power_before_long_long_overflow(void)
{
    long long n = 1;
    int power = 0;

    while (n < LLONG_MAX / 10) {
        n *= 10;
        power++;
    }
    return power;
}

long long my_pow10(unsigned n)
{
    long long pow = 1;

    if (n > max_power_before_long_long_overflow()) {
        return -1;
    }
    while (n--) {
        pow *= 10;
    }
    return pow;
}
