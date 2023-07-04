/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** core.c
*/

#include <my_graphics.h>
#include <my_rpg.h>

void my_function0(game_src_t* g_src, sfClock * clock,
                        int * step, mob_t * ami)
{
    g_src->game->crowd->player->draw->data->position.y += 1;
    ami->draw->data->position.y += 1;
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 1.5) {
        sfClock_restart(clock); *step += 1;
        sfVector3f bb_pos = ami->draw->data->position;
        bb_pos.y -= 40;
        speech_bubble_spawn(g_src->game, "Macrongue abuse.        ", bb_pos, 1);
        animation_off_draw(g_src->game->crowd->player->draw);
        animation_off_draw(ami->draw);
    }
}

void my_function1(game_src_t* g_src, sfClock * clock,
                        int * step, mob_t * ami)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 1.5) {
        sfClock_restart(clock); *step += 1;
        speech_bubble_clean(g_src->game);
        sfVector3f bb_pos = g_src->game->crowd->player->draw->data->position;
        bb_pos.y -= 40;
        speech_bubble_spawn(g_src->game, "Il faut se soulever !", bb_pos, 1);
    }
}

void my_function2(game_src_t* g_src, sfClock * clock,
                        int * step, mob_t * ami)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 1.5) {
        sfClock_restart(clock); *step += 1;
        speech_bubble_clean(g_src->game);
        sfVector3f bb_pos = ami->draw->data->position;
        bb_pos.y -= 20;
        speech_bubble_spawn(g_src->game,
            "Tu penses pouvoir eviter les CRS ?", bb_pos, 1);
    }
}

void my_function3(game_src_t* g_src, sfClock * clock,
                        int * step, mob_t * ami)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 1.5) {
        sfClock_restart(clock); *step += 1;
        speech_bubble_clean(g_src->game);
        sfVector3f bb_pos = g_src->game->crowd->player->draw->data->position;
        bb_pos.y -= 40;
        speech_bubble_spawn(g_src->game,
            "Je sais me deplacer avec Z Q S D.", bb_pos, 1);
    }
}

void my_function4(game_src_t* g_src, sfClock * clock, int * step, mob_t * ami)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 3) {
        sfClock_restart(clock); *step += 1;
        speech_bubble_clean(g_src->game);
        sfVector3f bb_pos = ami->draw->data->position; bb_pos.y -= 20;
        speech_bubble_spawn(g_src->game, "Montres moi.", bb_pos, 1);
    }
}
