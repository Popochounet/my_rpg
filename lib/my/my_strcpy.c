/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** ->   reimplements string.h's my_strcpy function
*/

char *my_strcpy(char *dest, const char *src)
{
    if (!dest || !src) {
        return dest;
    }
    unsigned i = 0;
    while (*(src + i)) {
        *(dest + i) = *(src + i);
        i++;
    }
    *(dest + i) = '\0';
    return dest;
}
