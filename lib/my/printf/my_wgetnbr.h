/*
** EPITECH PROJECT, 2022
** my_get_nbr.h
** File description:
** ->   protos for my_get_nbr
*/

#pragma once

#include <wchar.h>

int is_wchar_valid_in_nbr(wchar_t c);

int my_wnbr_strlen(const wchar_t *str);

int max_power_before_long_long_overflow(void);

long long my_pow10(int n);
