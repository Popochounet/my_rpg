/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that free a text struct
*/
#include "../include/text.h"

void free_text(text_t * text)
{
    if (text == NULL)
        return;
    if (text->text != NULL)
        sfText_destroy(text->text);
    if (text->font != NULL)
        sfFont_destroy(text->font);
    free(text);
}
