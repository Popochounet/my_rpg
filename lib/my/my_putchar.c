/*
** EPITECH PROJECT, 2022
** my_putchar.c
** File description:
** ->   puts a single char in stdout stream
*/

#include <unistd.h>

void my_dputchar(int fd, char c)
{
    write(fd, &c, 1);
}

void my_putchar(char c)
{
    my_dputchar(STDOUT_FILENO, c);
}
