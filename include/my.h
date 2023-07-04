/*
** EPITECH PROJECT, 2022
** header.h
** File description:
** ->   protos
*/

#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <wchar.h>
#include <stdarg.h>
#include <stdint.h>

typedef void (*destructor_t)(void *);
void free_all(void **allocs, void **destructors, size_t n);

char *my_calloc(size_t length);
void **my_calloc_pointers(size_t type_size, size_t n_elements);
void my_swap(int *a, int *b);

int my_abs(int n);
bool my_is_prime(int n);
long long my_pow10(unsigned n);
int my_log10(int n);

void my_dputchar(int fd, char c);
void my_putchar(char c);
void my_dputstr(int fd, char *str);
void my_putstr(char *str);
void my_dputs(int fd, char *str);
void my_puts(char *str);
char *my_evil_str(char *str);

bool is_char_valid_in_nbr(char c);
size_t my_nbr_strlen(const char *str);
long long my_pow10l(int n);

char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, size_t n);
int my_strcmp(const char *s1, const char *s2);
char my_toupper(char c);
char my_tolower(char c);
char *my_revstr(char *str);
void my_putchar(char c);
char *my_strchr(char *str, char c);
char *my_strnchr(char *str, size_t n, char c);
char *my_strrchr(char *str, char c);
char *my_strstr(char *str, const char *to_find);
char **my_str_to_word_array(const char *str);

int my_put_nbr(int nb);
char *my_itoa_base(intmax_t n, const char *base);
char *my_utoa_base(uintmax_t n, const char *base);
char *my_itoa(intmax_t n);
char *my_utoa(uintmax_t n);

char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);

long long my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);

int my_find_prime_sup(int nb);
int my_isneg(int n);

char *my_strcapitalize(char *str);
bool my_str_isalpha(const char *str);
char *my_strlowcase(char *str);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_strupcase(char *str);
long long my_getnbr(char const *str);
char *my_strndup(const char *str, size_t n);
char *my_strdup(const char *str);
char my_toupper(char c);
char my_tolower(char c);
int my_isalpha(char c);

int my_printf(const char *restrict format, ...);
int my_wprintf(const wchar_t *restrict format, ...);
int my_vprintf(const char *restrict format, va_list args);
int my_wvprintf(const wchar_t *restrict format, va_list args);

char *my_calloc(size_t length);
wchar_t *my_wcalloc(size_t length);
int my_wgetnbr(const wchar_t *str);
void my_wputchar(wchar_t c);
int my_wputstr(const wchar_t *str);
int my_wstrcmp(const wchar_t *s1, const wchar_t *s2);
wchar_t *my_wstrndup(const wchar_t *src, size_t n);
wchar_t *my_wstrdup(const wchar_t *src);
size_t my_strlen(const char *str);
size_t my_wstrlen(const wchar_t *str);
const wchar_t *my_wstrstr(const wchar_t *str, const wchar_t *to_find);

char *str_append_cstr(char *str, char *to_add);
char *str_substr(char *str, size_t start, size_t count);
char *str_insert(char *str, int index, char c);
char *str_pop(char *str, size_t index);
char *cstr_append_cstr(char *str, char *to_add);
char *cstr_append_str(char *str, char *to_add);
char *str_append_cstr(char *str, char *to_add);
char *str_append_str(char *str, char *to_add);
char *cstr_padding(char *str, int length, int left_padding, char c);
char *str_back(char *str);
char *cstr_prepend(char *str, char c);
char *str_prepend(char *str, char c);
char *cstr_append(char *str, char c);
char *str_append(char *str, char c);

size_t str_array_length(char **const array);
char **str_array_append(char **array, char *str);
char **make_str_array(char *str);
char **str_array_extend(char **array, char **add);
char **str_array_init(size_t n_strings);
void str_array_free(char **array, size_t length);
char **copy_str_array(char **array);

bool my_isdigit(char c);
bool my_isdigit_or_space(char c);
bool my_isspace(char c);
bool my_isalnum(char c);
bool my_isletter(char c);

size_t str_advance(char **ptr, size_t n);
size_t str_advance_char(char **ptr, char c);
size_t str_advance_char_not(char **ptr, char c);
size_t str_advance_pred(char **ptr, bool (*predicate)(char));
size_t str_advance_pred_not(char **ptr, bool (*predicate)(char));

size_t str_count(char *str, char c);
size_t str_count_pred(char *str, bool (*predicate)(char));

size_t str_ncount_str_no_overlap
(char *str, size_t str_len, size_t substr_start, size_t substr_len);
size_t str_ncount_str
(char *str, size_t str_len, size_t substr_start, size_t substr_length);
size_t str_count_str_no_overlap(char *str, char *substr);
size_t str_count_str(char *str, char *substr);

char *str_find(char *str, char c);
char *str_find_pred(char *str, bool (*predicate)(char));
char *str_rfind(char *str, char c);
char *str_rfind_pred(char *str, bool (*predicate)(char));

char *str_find_not(char *str, char c);
char *str_find_not_pred(char *str, bool (*predicate)(char));
char *str_rfind_not(char *str, char c);
char *str_rfind_not_pred(char *str, bool (*predicate)(char));

char **str_split(char *str, char delim);
char **str_split_pred(char *str, bool (*predicate)(char));

char *str_merge_array(char **array);
char *str_merge(unsigned n, ...);
void str_merge_in_place(char *str, unsigned n, ...);

extern const long double PI;
long double radian_to_degree(long double radian);
long double degree_to_radian(long double degree);

bool is_between(long double n1, long double n2, long double x);
