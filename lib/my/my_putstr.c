/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** ->   displays a string
** ->   allowed function : my_putchar
*/

#include <unistd.h>
#include <my.h>

void my_dputstr(int fd, char *str)
{
    while (str && *str) {
        my_dputchar(fd, *str++);
    }
}

void my_putstr(char *str)
{
    my_dputstr(STDOUT_FILENO, str);
}

void my_dputs(int fd, char *str)
{
    my_dputstr(fd, str);
    my_dputchar(fd, '\n');
}

void my_puts(char *str)
{
    my_dputs(STDOUT_FILENO, str);
}
