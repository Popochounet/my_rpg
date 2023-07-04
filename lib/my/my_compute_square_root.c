/*
** EPITECH PROJECT, 2022
** my_compute_square_root.c
** File description:
** ->   computes square root of parameter
*/

#include <stdbool.h>

int my_compute_square_root(int nb)
{
    unsigned i = 0;
    int power = 0;

    while (true) {
        power = i * i;
        if (power == nb) {
            return i;
        }
        if (power > nb) {
            return 0;
        }
        i++;
    }
}
