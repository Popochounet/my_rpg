/*
** EPITECH PROJECT, 2022
** flag_b.c
** File description:
** ->   %b prints unsigned integers in a binary base
*/

#include "my_printf.h"

wchar_t *flag_b(uintmax_t n)
{
    return my_wputnbr_base(n, L"01");
}
