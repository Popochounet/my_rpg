/*
** EPITECH PROJECT, 2022
** my_strupcase.c
** File description:
** ->   puts a string in uppercase
*/

char my_toupper(char c)
{
    return ('a' <= c && c <= 'z') ? c + ('A' - 'a') : c;
}

char *my_strupcase(char *str)
{
    for (int i = 0; str && *(str + i); i++) {
        *(str + i) = my_toupper(*(str + i));
    }
    return str;
}
