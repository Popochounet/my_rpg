/*
** EPITECH PROJECT, 2022
** my_compute_power_rec.c
** File description:
** ->   recursive function to compute nb raised to power p
*/

#include <limits.h>
#include <my.h>
#include <my_macros.h>

long long my_compute_power_rec(int n, int p)
{
    int previous_power = 0;

    if (p <= 0) {
        return p == 0;
    }
    if (n == 0) {
        return 0;
    }
    previous_power = my_compute_power_rec(n, p - 1);
    if (previous_power < 0 && previous_power < INT_MIN / ABS(n)) {
        return 0;
    }
    if (previous_power > 0 && previous_power > INT_MAX / ABS(n)) {
        return 0;
    }
    return n * previous_power;
}
