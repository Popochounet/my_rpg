/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** ->   converts string to int
** ->   allowed function : my_putchar
*/

#include <my.h>
#include <limits.h>
#include <stdio.h>

int check_sign(const char *str)
{
    int sign = 1;
    while (str && *str && (*str == '+' || *str == '-')) {
        if (*str++ == '-') {
            sign = !sign;
        }
    }
    return sign ? 1 : -1;
}

const char *find_nb_start(const char *str)
{
    while (str && *str && !('0' <= *str && *str <= '9')) {
        str++;
    }
    return str;
}

long long str_to_int(const char *str, int sign)
{
    long long n = 0;
    const int length = my_nbr_strlen(str);
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

long long my_getnbr(const char *const str)
{
    const char *nb_start = find_nb_start(str);
    const int sign = check_sign(str);
    return str_to_int(nb_start, sign);
}
