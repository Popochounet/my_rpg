/*
** EPITECH PROJECT, 2022
** my_isdigit.c
** File description:
** -> function to know if a char is a digit or not
*/

#include <my.h>

bool my_isdigit(char c)
{
    return c >= '0' && c <= '9';
}

bool my_isdigit_or_space(char c)
{
    return my_isdigit(c) || my_isspace(c);
}
