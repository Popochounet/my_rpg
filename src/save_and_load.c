/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** save_and_load.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

void refresh_player(player_t* player, sprite_t* player_sprite, game_t* game)
{
    sfTexture_destroy(player_sprite->texture);
    player_sprite->texture = init_player_text(player->type);
    set_texture_sprite(player_sprite, player_sprite->texture,
        (sfIntRect) {0, 0, 48, 72});
    update_stat_ui(player->stat, game->pause_menu->player->other[0]);
    update_stat_ui(player->stat, game->stat_ui);
    set_size_draw(player->exp.fill, get_size_draw(player->exp.fill));
    set_size_draw(player->hp.fill, get_size_draw(player->hp.fill));
}

void save_and_load(game_src_t* g_src)
{
    if (IS_RELEASED(g_src->game->pause_menu->b_save)) {
        audio_play_sfx(&g_src->audio,
        save_to_file(g_src->game->crowd->player) ? SFX_QUEST : SFX_ERROR);
        g_src->game->pause_menu->b_save->state = NONE;
    }
    if (IS_RELEASED(g_src->game->pause_menu->b_load)) {
        if (load_from_file(g_src->game->crowd->player)) {
            audio_play_sfx(&g_src->audio, SFX_QUEST);
            refresh_player(g_src->game->crowd->player,
            g_src->game->crowd->player->draw->drawable, g_src->game);
        } else
            audio_play_sfx(&g_src->audio, SFX_ERROR);
        g_src->game->pause_menu->b_load->state = NONE;
    }
}

//set_texture_sprite
