/*
** EPITECH PROJECT, 2022
** header.h
** File description:
** ->   protos
*/

#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include <wchar.h>

extern const int DEFAULT_PRECISION;

int
does_substr_match(const wchar_t *str, const wchar_t *substr, unsigned start);

wchar_t *u_my_putnbr_base(uintmax_t n, const wchar_t *base);

wchar_t *my_putnbr_base(intmax_t n, const wchar_t *base);

wchar_t *str_append(wchar_t *str, wchar_t c);

wchar_t *str_prepend(wchar_t *str, wchar_t c);

wchar_t *str_back(wchar_t *str);

wchar_t *str_padding(wchar_t *str, int length, int left_padding, wchar_t c);

wchar_t *str_append_str(wchar_t *str, wchar_t *to_add);

wchar_t *str_insert(wchar_t *str, int index, wchar_t c);

wchar_t *str_padding(wchar_t *str, int length, int left_padding, wchar_t c);

int my_printf(const char *restrict format, ...);

int my_isinf(long double n);

int my_isnan(long double n);

wchar_t *flag_di(intmax_t n, int precision);

wchar_t *flag_u(uintmax_t n, int precision);

wchar_t *flag_o(uintmax_t n, int precision);

wchar_t *flag_x(uintmax_t n, int lower, int precision);

wchar_t *flag_f(long double n, int decimals, int lower, int has_hashtag);

short get_exp10(long double n);

wchar_t *flag_p(void *ptr);

wchar_t *flag_e(long double n, int decimals, int lower, int has_hashtag);

wchar_t *flag_g(long double n, int decimals, int lower, int has_hashtag);

wchar_t *flag_a(long double n, int decimals, int lower, int has_hashtag);

wchar_t *flag_s(char *str, int precision);

wchar_t *wflag_s(wchar_t *str, int precision);

wchar_t *flag_c(int c);

wchar_t *wflag_c(wint_t c);

wchar_t *flag_b(uintmax_t n);

wchar_t *flag_upper_s(char *str);

wchar_t to_lower(wchar_t c);

unsigned flag_start_point(wchar_t *format, int start);

unsigned flag_length(const wchar_t *format, int start);

int char_in_str(const wchar_t *str, wchar_t c);

wchar_t *str_to_wstr(const char *str);

typedef struct {
    int has_hyphen;
    int has_plus;
    int has_space;
    int has_hashtag;
    int has_zero;
    int field_width;
    int is_precision_specified;
    int precision;
    wchar_t *length_modifier;
    wchar_t conversion_specifier;
} flag_struct_t;

typedef struct {
    flag_struct_t *flag_struct;
    wchar_t *flag_str;
    int is_good;
} flag_t;

int get_int_precision(flag_t *flag);

int get_str_precision(flag_t *flag);

void free_flag(flag_t *flag);

flag_t *parse_flag(const wchar_t *format, va_list args);

wchar_t *apply_hashtag(wchar_t *str, flag_t *flag);

wchar_t *apply_plus_and_space(wchar_t *str, flag_t *flag);

wchar_t *


apply_padding(wchar_t *str, flag_t *flag);

void flag_n(intmax_t *integer, int written, wchar_t *length_modifier);

typedef union {
    intmax_t signed_int;
    uintmax_t unsigned_int;
    char char_;
    wchar_t wchar;
    char *str;
    wchar_t *wstr;
    long double floating_point;
    intmax_t *flag_n_ptr;
    void *flag_p_ptr;
} types_t;

int read_arg(types_t *arg, va_list args, flag_t *flag);
