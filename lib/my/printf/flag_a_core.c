/*
** EPITECH PROJECT, 2022
** flag_a_core.c
** File description:
** ->   math functions for flag_a
*/

#include <stdlib.h>
#include <my.h>
#include "flag_a.h"
#include "my_printf.h"

short get_exp2(long double n)
{
    short exp = 0;
    if (n > 1.L) {
        while (n >= 2.L) {
            exp++;
            n /= 2.L;
        }
    } else {
        while (n < 1.L) {
            exp--;
            n *= 2.L;
        }
    }
    return exp;
}

long double pow2(short n)
{
    long double power = 1.L;

    while (n > 0) {
        power *= 2.L;
        n--;
    }
    while (n < 0) {
        power /= 2.L;
        n++;
    }
    return power;
}
