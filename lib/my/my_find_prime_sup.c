/*
** EPITECH PROJECT, 2022
** my_find_prime_sup.c
** File description:
** ->   find the smallest greater prime number greater or equal to param
*/

#include <limits.h>
#include <my.h>

int my_find_prime_sup(int n)
{
    if (n <= 2) {
        return 2;
    }
    for (int i = n + !(n % 2); i < INT_MAX; i += 2) {
        if (my_is_prime(i)) {
            return i;
        }
    }
    return 0;
}
