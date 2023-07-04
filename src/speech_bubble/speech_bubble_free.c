/*
** EPITECH PROJECT, 2023
** speech_bubble_free.c
** File description:
** -> Frees speech bubble
*/

#include <my_macros.h>
#include <speech_bubble.h>

void speech_bubble_free(bubble_t **bubble, bool free_draws)
{
    RETURN_IF(!bubble || !(*bubble));
    FREE_IF_ALLOCATED((*bubble)->clock, sfClock_destroy);
    if (free_draws) {
        FREE_IF_ALLOCATED((*bubble)->sprite, free_single_draw);
        FREE_IF_ALLOCATED((*bubble)->text, free_single_draw);
    }
}
