/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that parse a tmx file into a sprite list
*/
#include "my.h"
#include <stdio.h>

int mystrlen ( char const * str )
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char * mystrcat ( char * dest , char const * src )
{
    int lentt = mystrlen(dest) + mystrlen(src);
    int lend = mystrlen(dest);
    char * pointer;
    int i = 0;
    while (src[i] != '\0') {
        pointer = dest + lend + i;
        *pointer = src[i];
        i++;
    }
    pointer = dest + lentt;
    *pointer = '\0';
    return dest;
}

int mystrncmp ( char const * s1, char const * s2, int n )
{
    int len1 = 0;
    int len2 = 0;
    int biggest = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        len1++;
    } for (int i = 0; s2[i] != '\0'; i++) {
        len2++;
    } if (len1 >= len2) {
        biggest = len1;
    } else {
        biggest = len2;
    } for (int i = 0; i < biggest && i < n; i++) {
        int d = s1[i] - s2[i];
        if (d != 0) {
            return d;
        }
    }
    return 0;
}

char * mystrcpy ( char * dest , char const * src )
{
    int len = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
        len++;
    }
    dest[len] = '\0';
    return dest;
}
