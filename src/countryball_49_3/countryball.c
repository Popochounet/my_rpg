/*
** EPITECH PROJECT, 2023
** countryball.c
** File description:
** -> Countryball animation of 49.3
*/

#include <stdbool.h>
#include <my_macros.h>
#include <countryball.h>

const char *const SPRITESHEET_PATH =
    "images/spritesheets/49_3_spritesheet.png";

const unsigned N_COLUMNS = 6;
const unsigned N_LINES = 8;
const unsigned N_FRAMES = N_COLUMNS * N_LINES;
const unsigned FRAME_DELAY_MICROSECONDS = 100'000;

const sfVector2f FRAME_SIZE = {
    .x = 579,
    .y = 454
};

const char *const LOSE_TEXT = "Victoire du 49.3 par K.O.";
const sfVector2f LOSE_TEXT_POS = {
    .x = 15.f,
    .y = 15.f
};

/*
    Initializes a countryball structure without error handling.
*/
static bool countryball_init_impl(countryball_t *countryball)
{
    const sfWindowStyle style = sfTitlebar | sfClose;
    const sfVideoMode mode = {
        .width = FRAME_SIZE.x,
        .height = FRAME_SIZE.y,
        .bitsPerPixel = 32
    };
    bool status = countryball != NULL;

    RETURN_VALUE_IF(!countryball, false);
    status &= (countryball->sprite = sfSprite_create()) != NULL;
    status &= (countryball->clock = sfClock_create()) != NULL;
    status &= (countryball->lose_text = sfText_create()) != NULL;
    status &= (countryball->window =
        sfRenderWindow_create(mode, "49.3", style, NULL)) != NULL;
    status &= (countryball->spritesheet =
        sfTexture_createFromFile(SPRITESHEET_PATH, NULL)) != NULL;
    status &= (countryball->font =
        sfFont_createFromFile("fonts/Arial.ttf")) != NULL;
    return status;
}

/*
    Properly initializing a countryball structure (with error handling).
*/
static bool countryball_init(countryball_t *countryball)
{
    if (!countryball_init_impl(countryball)) {
        countryball_free(countryball);
        return false;
    }
    sfSprite_setTexture(countryball->sprite, countryball->spritesheet, false);
    sfText_setString(countryball->lose_text, LOSE_TEXT);
    sfText_setPosition(countryball->lose_text, LOSE_TEXT_POS);
    sfText_setFillColor(countryball->lose_text, sfBlack);
    sfText_setFont(countryball->lose_text, countryball->font);
    return true;
}

static void countryball_draw
(countryball_t *countryball, bool draw_next, audio_t *audio)
{
    static unsigned n_line = 0;
    static unsigned n_column = 0;
    const sfIntRect frame = {
        .width = FRAME_SIZE.x,
        .height = FRAME_SIZE.y,
        .left = n_column * FRAME_SIZE.x,
        .top = n_line * FRAME_SIZE.y,
    };

    if (n_line == 0 && n_column == 0) {
        audio_play_sfx(audio, SFX_49_3);
    }
    sfSprite_setTextureRect(countryball->sprite, frame);
    sfRenderWindow_drawSprite(countryball->window, countryball->sprite, NULL);
    sfRenderWindow_drawText(countryball->window, countryball->lose_text, NULL);
    if (draw_next) {
        n_line += n_column == N_COLUMNS;
        n_line *= n_line != N_LINES;
        n_column = n_column == N_COLUMNS ? 0 : n_column + 1;
    }
}

static void countryball_handle_events(countryball_t *countryball)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(countryball->window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(countryball->window);
            return;
        }
        if (!sfRenderWindow_hasFocus(countryball->window)) {
            sfRenderWindow_requestFocus(countryball->window);
        }
    }
}

bool countryball_49_3(audio_t *audio)
{
    countryball_t countryball;
    bool is_wait_time_ok = false;

    RETURN_VALUE_IF(!audio || !countryball_init(&countryball), false);
    while (sfRenderWindow_isOpen(countryball.window)) {
        sfRenderWindow_setPosition(countryball.window, (sfVector2i){700, 300});
        is_wait_time_ok = sfClock_getElapsedTime
            (countryball.clock).microseconds >= FRAME_DELAY_MICROSECONDS;
        countryball_handle_events(&countryball);
        sfRenderWindow_clear(countryball.window, sfWhite);
        countryball_draw(&countryball, is_wait_time_ok, audio);
        sfRenderWindow_display(countryball.window);
        if (is_wait_time_ok) {
            sfClock_restart(countryball.clock);
        }
    }
    sfSound_stop(audio->sfx_49_3.sound);
    countryball_free(&countryball);
    return true;
}
