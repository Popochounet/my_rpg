/*
** EPITECH PROJECT, 2022
** my_strncmp.c
** File description:
** ->   compares n first bytes of two strings
*/

#include <my.h>

int my_strncmp(const char *s1, const char *s2, size_t n)
{
    if (!s1 || !s2 || n <= 0) {
        return 0;
    }
    if (n > my_strlen((char *)s1) && n > my_strlen((char *)s2)) {
        return my_strcmp(s1, s2);
    }
    char s1_cut[n + 1];
    char s2_cut[n + 1];
    s1_cut[n] = '\0';
    s2_cut[n] = '\0';
    my_strncpy(&s1_cut[0], s1, n);
    my_strncpy(&s2_cut[0], s2, n);
    return my_strcmp(&s1_cut[0], &s2_cut[0]);
}
