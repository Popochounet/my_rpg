/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that change the string of a text
*/
#include "../include/text.h"

void set_string_text(text_t * text, const char * string)
{
    text->string = string;
    if (text->string != NULL) {
        sfText_setString(text->text, text->string);
    }
}
