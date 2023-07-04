/*
** EPITECH PROJECT, 2023
** is_between.c
** File description:
** -> checks if a number is between two other numbers
*/

#include <stdbool.h>

bool is_between(long double n1, long double n2, long double x)
{
    return (n1 > n2) ? is_between(n2, n1, x) : (n1 <= x && x <= n2);
}
