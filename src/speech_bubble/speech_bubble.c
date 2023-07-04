/*
** EPITECH PROJECT, 2023
** speech_bubble.c
** File description:
** -> Displays text in a speech bubble
*/

#include <my_graphics.h>
#include <my_macros.h>
#include <speech_bubble.h>
#include <my_rpg.h>

const char *SPEECH_BUBBLE_SPRITE_PATH = "images/bulle_de_texte.png";

const unsigned SPEECH_BUBBLE_HEIGHT = 64;
const unsigned SPEECH_BUBBLE_WIDTH = 256;

const sfVector2f SPEECH_BUBBLE_SIZE = {
    .x = SPEECH_BUBBLE_WIDTH,
    .y = SPEECH_BUBBLE_HEIGHT
};

const sfIntRect SPEECH_BUBBLE_AREA = {
    .left = 0,
    .top = 0,
    .width = SPEECH_BUBBLE_WIDTH,
    .height = SPEECH_BUBBLE_HEIGHT
};

/*
    Allocates text draw_t, returns true if succeeds, otherwise false.
    NOTE: bubble must be a valid pointer.
*/
static bool speech_bubble_text_alloc
(bubble_t *bubble, char *str, sfVector3f pos, sfTexture *bubble_texture)
{
    const sfVector3f new_pos = {
        .x = pos.x + SPEECH_BUBBLE_WIDTH * 0.15f,
        .y = pos.y - SPEECH_BUBBLE_HEIGHT,
        .z = pos.z
    };
    data_t *data = create_data(new_pos, SPEECH_BUBBLE_SIZE, 0);
    text_t *text = data ? create_text(str, NULL, sfBlack) : NULL;
    draw_t *draw = text ? create_draw(text, TEXT, data) : NULL;

    if (!draw) {
        FREE_IF_ALLOCATED(data, free);
        FREE_IF_ALLOCATED(text, free_text);
    } else {
        speech_bubble_resize_text_and_move(data, draw, str, bubble_texture);
    }
    bubble->text = draw;
    return draw != NULL;
}

/*
    Allocates bubble image draw_t, returns true if succeeds, otherwise false.
    NOTE: bubble and texture both must be valid pointers.
*/
static bool speech_bubble_alloc
(bubble_t *bubble, sfTexture *texture, sfVector3f pos)
{
    const sfVector3f new_pos = {
        .x = pos.x,
        .y = pos.y - SPEECH_BUBBLE_HEIGHT,
        .z = pos.z
    };
    const sfIntRect area = SPEECH_BUBBLE_AREA;

    data_t *data = create_data(new_pos, SPEECH_BUBBLE_SIZE, 0);
    sprite_t *sprite = data ? create_sprite(texture, area) : NULL;
    draw_t *draw = sprite ? create_draw(sprite, SPRITE, data) : NULL;

    if (!draw) {
        FREE_IF_ALLOCATED(data, free);
        FREE_IF_ALLOCATED(sprite, free_sprite);
    }
    bubble->sprite = draw;
    return draw != NULL;
}

static bubble_t *speech_bubble_create
(char *str, sfVector3f pos, float time, game_t *game)
{
    sfTexture *texture =
        sfTexture_createFromFile(SPEECH_BUBBLE_SPRITE_PATH, NULL);
    bubble_t *bubble = malloc(sizeof(bubble_t));
    bool status = bubble != NULL;

    RETURN_VALUE_IF(!status, NULL);
    bubble->time = time;
    status &= speech_bubble_alloc(bubble, texture, pos);
    status &= speech_bubble_text_alloc(bubble, str, pos, texture);
    status &= (bubble->clock = sfClock_create()) != NULL;
    if (!status) {
        speech_bubble_free(&bubble, true);
        free(bubble);
        FREE_IF_ALLOCATED(texture, sfTexture_destroy);
        return NULL;
    }
    return bubble;
}

bool speech_bubble_spawn(game_t* game, char* str, sfVector3f pos, float time)
{
    bubble_t *bubble = NULL;

    RETURN_VALUE_IF(!game || !str || !game->layer_fx, false);
    bubble = speech_bubble_create(str, pos, time, game);
    RETURN_VALUE_IF(!bubble, false);
    if (!speech_bubble_append(&game->list_bubbles, bubble)) {
        speech_bubble_free(&bubble, true);
        return false;
    }
    append_draw_layer(game->layer_fx, bubble->text);
    append_draw_layer(game->layer_fx, bubble->sprite);
    return true;
}

void speech_bubble_clean(game_t *game)
{
    sfTime time;

    RETURN_IF(!game || !game->list_bubbles || !game->layer_fx);
    while (true) {
        time = sfClock_getElapsedTime(game->list_bubbles->bubble->clock);
        if (time.microseconds > game->list_bubbles->bubble->time * 1'000'000) {
            remove_single_draw(game->list_bubbles->bubble->sprite);
            remove_single_draw(game->list_bubbles->bubble->text);
            speech_bubble_remove(&game->list_bubbles);
            game->layer_fx->draw = NULL;
        }
        if (!game->list_bubbles || !game->list_bubbles->next) {
            break;
        }
        game->list_bubbles = game->list_bubbles->next;
    }
    while (game->list_bubbles && game->list_bubbles->previous) {
        game->list_bubbles = game->list_bubbles->previous;
    }
}
