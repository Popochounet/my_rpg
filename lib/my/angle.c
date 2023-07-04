/*
** EPITECH PROJECT, 2023
** angle.c
** File description:
** -> angle conversion funtions
*/

#include <my.h>

const long double PI = 3.14159265358979323846L;

long double degree_to_radian(long double degree)
{
    return degree / 180.L * PI;
}

long double radian_to_degree(long double radian)
{
    return radian / PI * 180.L;
}
