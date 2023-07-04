/*
** EPITECH PROJECT, 2022
** char_traits.c
** File description:
** -> functions to check a char's traits, such as if it's a letter
*/

#include <stdbool.h>
#include <my.h>

bool my_isletter(char c)
{
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

bool my_isalnum(char c)
{
    return my_isletter(c) || my_isdigit(c) || c == '_';
}
