/*
** EPITECH PROJECT, 2022
** my_strlowcase.c
** File description:
** ->   puts a string in lowercase
*/

char my_tolower(char c)
{
    return ('A' <= c && c <= 'Z') ? c + ('a' - 'A') : c;
}

char *my_strlowcase(char *str)
{
    for (int i = 0; str && *(str + i); i++) {
        *(str + i) = my_tolower(*(str + i));
    }
    return str;
}
