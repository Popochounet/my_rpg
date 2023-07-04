/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** resolution.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

void change_mouse_from_resolution(sfEvent* evt, sfVector2f size)
{
    if (evt->type == sfEvtMouseButtonPressed ||
        evt->type == sfEvtMouseButtonReleased) {
        evt->mouseButton.x *= WD_WIDTH / size.x;
        evt->mouseButton.y *= WD_HEIGHT / size.y;
    } else if (evt->type == sfEvtMouseMoved) {
        evt->mouseMove.x *= WD_WIDTH / size.x;
        evt->mouseMove.y *= WD_HEIGHT / size.y;
    }
}

void change_resolution(window_t* wd, sfVector2f s)
{
    if (wd->fullscreen)
        window_windowed(wd, "49.3",
        (const sfVideoMode){WD_WIDTH, WD_HEIGHT, 32}, NULL);
    wd->size = s;
    sfRenderWindow_setSize(wd->window, (sfVector2u){s.x, s.y});
}

void resolutions(window_t* wd, menu_cat_t* settings)
{
    if (IS_RELEASED(settings->btn[1]) && !wd->fullscreen) {
        window_fullscreen(wd, "49.3",
            (const sfVideoMode){WD_WIDTH, WD_HEIGHT, 32}, NULL);
        settings->btn[2]->state = NONE;
    } if (IS_RELEASED(settings->btn[2])) {
        change_resolution(wd, set_2vector(1920, 1080));
        settings->btn[2]->state = NONE;
    } if (IS_RELEASED(settings->btn[3])) {
        change_resolution(wd, set_2vector(1280, 720));
        settings->btn[3]->state = NONE;
    } if (IS_RELEASED(settings->btn[4])) {
        change_resolution(wd, set_2vector(960, 540));
        settings->btn[4]->state = NONE;
    } if (IS_RELEASED(settings->btn[5])) {
        change_resolution(wd, set_2vector(640, 360));
        settings->btn[5]->state = NONE;
    }
}
