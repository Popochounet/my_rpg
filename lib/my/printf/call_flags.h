/*
** EPITECH PROJECT, 2022
** call_flags.h
** File description:
** ->   protos of functions calling the right flag for each value type
*/

#pragma once
#include <wchar.h>

struct flag_t;
union types_t;

wchar_t *call_unsigned(flag_t *flag, types_t *arg);

wchar_t *call_float(flag_t *flag, types_t *arg);

wchar_t *call_string(flag_t *flag, types_t *arg);

wchar_t *call_string(flag_t *flag, types_t *arg);

wchar_t *call_char(flag_t *flag, types_t *arg);

wchar_t *call_additional_flags(flag_t *flag, types_t *arg);
