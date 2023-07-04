/*
** EPITECH PROJECT, 2022
** my_strncpy.c
** File description:
** ->   reimplements string.h's my_strncpy function
*/

static void fill_zeros(char *dest, int n)
{
    while (n--) {
        *dest++ = '\0';
    }
}

char *my_strncpy(char *dest, const char *src, int n)
{
    if (!src || !dest || n <= 0) {
        return dest;
    }
    for (int i = 0; i < n; i++) {
        if (!*(src + i)) {
            fill_zeros(dest + i, n - i);
            break;
        } else {
            *(dest + i) = *(src + i);
        }
    }
    return dest;
}
