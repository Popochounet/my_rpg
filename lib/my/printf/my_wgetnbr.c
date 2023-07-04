/*
** EPITECH PROJECT, 2022
** my_wgetnbr.c
** File description:
** ->   converts string to int
*/

#include <limits.h>
#include <stdio.h>
#include <wchar.h>
#include "my_wgetnbr.h"

static int check_sign(const wchar_t *str)
{
    int sign = 1;
    while (str && *str && (*str == '+' || *str == '-')) {
        if (*str++ == '-') {
            sign = !sign;
        }
    }
    return sign ? 1 : -1;
}

static const wchar_t *find_nb_start(const wchar_t *str)
{
    while (str && *str && !('0' <= *str && *str <= '9')) {
        str++;
    }
    return str;
}

static int str_to_int(const wchar_t *str, int sign)
{
    long long n = 0;
    const int length = my_wnbr_strlen(str);
    long long power = my_pow10(length - 1);
    if (power == -1) {
        return 0;
    }
    while (*str && '0' <= *str && *str <= '9') {
        n += (*str - '0') * power;
        if (sign == 1 && -n > INT_MAX) {
            return 0;
        }
        if (sign == -1 && n < INT_MIN) {
            return 0;
        }
        str++;
        power /= 10;
    }
    return n * sign;
}

int my_wgetnbr(const wchar_t *str)
{
    const wchar_t *nb_start = find_nb_start(str);
    const int sign = check_sign(str);
    return str_to_int(nb_start, sign);
}
