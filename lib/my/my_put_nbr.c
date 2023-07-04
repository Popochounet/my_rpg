/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** ->   displays a number (should be reimplemented in a recursive way)
*/

#include <my.h>
#include <stdlib.h>

int my_log(long long n)
{
    int log = 0;
    if (n <= 0) {
        return n == 0;
    }
    while (n) {
        n /= 10;
        log++;
    }
    return log;
}

int my_put_nbr(int nb)
{
    long long n = nb;
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    const int buf_size = my_log(n);
    char buf[buf_size];
    for (int i = 0; i < buf_size; i++) {
        buf[i] = '0' + n % 10;
        n /= 10;
    }
    for (int i = buf_size - 1; i >= 0; i--) {
        my_putchar(buf[i]);
    }
    return 0;
}
