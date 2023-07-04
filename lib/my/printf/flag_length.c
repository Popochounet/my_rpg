/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** flag_length
*/

#include <wchar.h>

int char_in_wstr(const wchar_t *str, wchar_t c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

unsigned int flag_length(const wchar_t *format, int start)
{
    int length = 1;
    wchar_t *flag_string = L"csdioxXufFeEaAgGnp%";
    int y = start + 1;

    for (; *format && !char_in_wstr(flag_string, format[y]); y++) {
        length++;
    }
    return length;
}

int flag_start_point(wchar_t *format, int start)
{
    while (format[start] != '\0' && format[start] != '%') {
        start++;
    }
    return format[start] == '\0' ? -1 : start;
}
