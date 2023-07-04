/*
** EPITECH PROJECT, 2022
** my_isneg.c
** File description:
** ->   displays N if its parameter is negative, otherwise P if positive or null
** ->   allowed function : my_putchar
*/

#include <my.h>

int my_isneg(int n)
{
    my_putchar(n < 0 ? 'N' : 'P');
    return 0;
}
