/*
** EPITECH PROJECT, 2023
** free_all.c
** File description:
** -> macro to free all pointers in array with custom destructor
*/

#include <stddef.h>
#include <my_macros.h>
#include <my.h>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"

void free_all(void **allocs, void **destructors, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        FREE_IF_ALLOCATED(allocs[i], ((destructor_t)(destructors[i])));
    }
}

#pragma GCC diagnostic pop
