/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** win_pop_up.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

void free_win_pop_up(sfRenderWindow* wd, sfText* txt, sfFont* fnt)
{
    sfText_destroy(txt);
    sfFont_destroy(fnt);
    sfRenderWindow_destroy(wd);
}

void win_pop_up_event(sfRenderWindow* pop_up_wd, sfEvent *evt)
{
    while (sfRenderWindow_pollEvent(pop_up_wd, evt)) {
        if (evt->type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(pop_up_wd);
    }
}

void win_pop_up_core(sfRenderWindow* pop_up_wd, sfText* txt)
{
    sfClock* clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(pop_up_wd, 60);
    for (sfEvent evt; sfRenderWindow_isOpen(pop_up_wd);) {
        win_pop_up_event(pop_up_wd, &evt);
        if (!sfRenderWindow_hasFocus(pop_up_wd))
            sfRenderWindow_requestFocus(pop_up_wd);
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.01) {
            sfClock_restart(clock);
            sfRenderWindow_clear(pop_up_wd, sfWhite);
            sfRenderWindow_drawText(pop_up_wd, txt, NULL);
            sfRenderWindow_display(pop_up_wd);
        }
    }
    sfClock_destroy(clock);
}

void win_pop_up(void)
{
    sfVideoMode mode = {600, 400, 32};
    sfRenderWindow* pop_up_wd = sfRenderWindow_create(mode, "VOUS AVEZ GAGNE !",
    sfClose, NULL);
    char text[255] = "Bravo, vous avez ralie plein de manifestant\na votre caus"
    "e et avez vaincu le mechant\nMacrongue !!!\nMalheuresement, cela n'a pas s"
    "uffit, et \nla reforme des retraites n'a pas ete\nretirees...\n\n\t\tBAD E"
    "NDING";
    sfText* txt = sfText_create();
    sfFont* fnt = sfFont_createFromFile("./fonts/Arial.ttf");
    sfText_setFont(txt, fnt);
    sfText_setString(txt, text);
    sfText_setColor(txt, sfBlack);
    win_pop_up_core(pop_up_wd, txt);
    free_win_pop_up(pop_up_wd, txt, fnt);
}
