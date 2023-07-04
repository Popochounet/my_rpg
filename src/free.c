/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** free.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

static void free_button_list(list_button_t** l_btn)
{
    RETURN_IF(!l_btn || !(*l_btn));
    if ((*l_btn)->btn && (*l_btn)->btn->s_btn) {
        free((*l_btn)->btn->s_btn);
        (*l_btn)->btn->s_btn = NULL;
    }
    FREE_IF_ALLOCATED((*l_btn)->btn, free);
    free(*l_btn);
    *l_btn = NULL;
}

void free_menu(menu_t *menu)
{
    RETURN_IF(!menu);
    FREE_IF_ALLOCATED(menu->settings->btn, free);
    FREE_IF_ALLOCATED(menu->settings->s_btn, free);
    FREE_IF_ALLOCATED(menu->settings->title, free);
    FREE_IF_ALLOCATED(menu->settings, free);
    FREE_IF_ALLOCATED(menu, free);
}

void free_crowd(crowd_t *crowd)
{
    RETURN_IF(!crowd);
    sfClock_destroy(crowd->player->clock);
    for (int i = 0; i < CROWD_SIZE; i++) {
        sfClock_destroy(crowd->cop[i]->clock);
        free(crowd->cop[i]);
        free(crowd->mob[i]);
    }
    free(crowd->mob);
    free(crowd->cop);
    free(crowd->player);
    free(crowd);
}

void free_g_src(game_src_t* g_src)
{
    list_button_t *next = NULL;

    RETURN_IF(!g_src);
    while (g_src->all_btn) {
        next = g_src->all_btn->next;
        free_button_list(&g_src->all_btn);
        g_src->all_btn = next;
    }
    if (g_src->game->crowd) {
        if (g_src->game->crowd->boss)
            free_single_cop(&g_src->game->crowd->boss);
        if (g_src->game->crowd->player)
            FREE_IF_ALLOCATED(g_src->game->crowd->player->weapon_draw, free);
    }
    speech_bubble_remove_all(&g_src->game->list_bubbles);
    FREE_IF_ALLOCATED(g_src->game->crowd, free_crowd);
    FREE_IF_ALLOCATED(g_src->menu, free_menu);
    free(g_src);
}

void free_main(window_t *window, game_src_t *g_src)
{
    FREE_IF_ALLOCATED(window, free_window);
    audio_free(&g_src->audio);
    FREE_IF_ALLOCATED(g_src, free_g_src);
}
