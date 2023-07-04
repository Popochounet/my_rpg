/*
** EPITECH PROJECT, 2023
** my_isspace.c
** File description:
** -> tells if a char is a space (space, tabulation, or carriage return)
*/

#include <stdbool.h>

bool my_isspace(char c)
{
    return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}
