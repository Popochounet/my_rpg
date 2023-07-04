/*
** EPITECH PROJECT, 2023
** speech_bubble_spawn.c
** File description:
** -> Spawns speech bubbles
*/

#include <my_macros.h>
#include <speech_bubble.h>

bool speech_bubble_append
(list_bubble_t **head, bubble_t *bubble)
{
    list_bubble_t *node = head ? malloc(sizeof(list_bubble_t)) : NULL;

    RETURN_VALUE_IF(!head || !node, false);
    node->bubble = bubble;
    node->previous = *head;
    node->next = NULL;
    if (!(*head)) {
        *head = node;
    } else {
        (*head)->next = node;
    }
    return true;
}

bool speech_bubble_remove(list_bubble_t **bubble)
{
    const bool is_ok = bubble && *bubble;
    list_bubble_t *const next = is_ok ? (*bubble)->next : NULL;
    list_bubble_t *const previous = is_ok ? (*bubble)->previous : NULL;

    RETURN_VALUE_IF(!is_ok, false);
    if ((*bubble)->next) {
        (*bubble)->next->previous = previous;
    }
    if ((*bubble)->previous) {
        (*bubble)->previous->next = next;
    }
    free((*bubble)->bubble);
    free(*bubble);
    *bubble = next;
    return true;
}

void speech_bubble_remove_all(list_bubble_t **bubble)
{
    RETURN_IF(!bubble || !(*bubble));
    while (*bubble) {
        speech_bubble_remove(bubble);
    }
}
