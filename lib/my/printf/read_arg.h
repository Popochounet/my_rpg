/*
** EPITECH PROJECT, 2022
** read_arg.h
** File description:
** ->   protos for va_list's params reading
*/

#pragma once
#include <stdarg.h>

struct flag_t;
union types_t;

int cast_chars(types_t *arg, va_list args, flag_t *flag);

int cast_strings(types_t *arg, va_list args, flag_t *flag);

int cast_unsigned_integers(types_t *arg, flag_t *flag, va_list args);

int cast_signed_integers(types_t *arg, flag_t *flag, va_list args);

int cast_floats(types_t *arg, flag_t *flag, va_list args);

int cast_pointers(types_t *arg, va_list args, flag_t *flag);
