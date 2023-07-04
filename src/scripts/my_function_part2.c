/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** core.c
*/

#include <my_graphics.h>
#include <my_rpg.h>

sfVector2f move_player(player_t *player, window_t *wd);

void my_function5(game_src_t* g_src, float * move, int * step, void ** var)
{
    sfVector2f moves = move_player(g_src->game->crowd->player,
        (window_t *)var[1]);
    float ftg = moves.x + moves.y;
    *move += (ftg < 0) ? -ftg : ftg;
    if (*move > 30) {
        *step += 1;
        speech_bubble_clean(g_src->game);
        sfVector3f bb_pos = ((mob_t *)var[0])->draw->data->position;
        bb_pos.y -= 20;
        speech_bubble_spawn(g_src->game, "Pas mal.", bb_pos, 1);
    }
}

void my_function6(game_src_t* g_src, sfClock * clock, int * step, mob_t * ami)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 1.5) {
        sfClock_restart(clock); *step += 1;
        speech_bubble_clean(g_src->game);
        sfVector3f bb_pos = ami->draw->data->position; bb_pos.y -= 20;
        speech_bubble_spawn(g_src->game,
            "Il te faut 30 grevistes.", bb_pos, 1);
    }
}

void my_function7(game_src_t* g_src, sfClock * clock, int * step, mob_t * ami)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 1.5) {
        sfClock_restart(clock); *step += 1;
        speech_bubble_clean(g_src->game);
        sfVector3f bb_pos = ami->draw->data->position; bb_pos.y -= 20;
        speech_bubble_spawn(g_src->game, "Disparition ninja !", bb_pos, 1);
        set_animation_draw(g_src->game->crowd->player->draw,
            (sfIntRect) {0, 0, 48, 72}, 11, true);
    }
}
