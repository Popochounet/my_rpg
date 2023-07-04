/*
** EPITECH PROJECT, 2023
** free_cop.c
** File description:
** -> Frees a cop_t structure.
*/

#include <my_rpg.h>

// pointer to a cop_t*, not a cop_t* array
void free_single_cop(cop_t **cop)
{
    RETURN_IF(!cop || !(*cop));
    FREE_IF_ALLOCATED((*cop)->clock, sfClock_destroy);
    FREE_IF_ALLOCATED(*cop, free);
}
