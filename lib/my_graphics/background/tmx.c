/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that parse a tmx file into a sprite list
*/
#include "../include/background.h"

tmx_t * create_tmx(tmx_t * previous)
{
    tmx_t * tmx = malloc(sizeof(tmx_t));
    tmx->id = 0;
    tmx->width = 0;
    tmx->height = 0;
    tmx->path = NULL;
    tmx->next = NULL;
    tmx->previous = previous;
    return tmx;
}

void free_tmx(tmx_t * tmx)
{
    tmx_t * next = tmx;
    while (next != NULL) {
        next = next->next;
        free(tmx->path);
        free(tmx);
        tmx = next;
    }
}
