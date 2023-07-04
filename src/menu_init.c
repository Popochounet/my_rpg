/*
** EPITECH PROJECT, 2023
** menu_init.c
** File description:
** -> Menu initialization
*/

#include <my_macros.h>
#include <my_rpg.h>

layer_t* init_background(void)
{
    layer_t* bg_l = create_layer(set_2vector(WD_WIDTH, WD_HEIGHT), NULL);
    draw_t* bg = create_draw(create_shape(RECT, SF_GREY, sfWhite, 5), SHAPE,
    create_data(set_3vector(30, 30, 0), set_2vector(1860, 1020), 0));
    append_draw_layer(bg_l, bg);
    bg_l->show = false;
    return bg_l;
}

static bool append_btn_menu(window_t* wd, menu_t* menu)
{
    if (!(menu->bg_l = init_background())) {
        return false;
    }
    menu->b_resume = append_button_layer(menu->menu_l, menu->b_resume);
    menu->b_start = append_button_layer(menu->menu_l, menu->b_start);
    menu->b_settings = append_button_layer(menu->menu_l, menu->b_settings);
    menu->b_quit = append_button_layer(menu->menu_l, menu->b_quit);
    append_layer(wd->splash, menu->menu_l);
    append_layer(wd->splash, menu->bg_l);
    return true;
}

/*
    Unsafe menu initialization (no error handling).
*/
static bool init_menu_impl(window_t *wd, list_button_t **all_btn, menu_t *menu)
{
    const sfVector2f size = set_2vector(300, 75);

    RETURN_VALUE_IF(!wd || !all_btn || !menu, false);
    menu->show = true;
    menu->menu_l = create_layer(set_2vector(WD_WIDTH, WD_HEIGHT), NULL);
    menu->b_resume = set_button
        (all_btn, "REPRENDRE VOS\nEXPLOITS", set_3vector(100, 900, 0), size);
    menu->b_start = set_button
        (all_btn, "MANIFESTER", set_3vector(550, 900, 0), size);
    menu->b_settings = set_button
        (all_btn, "PLANIFICATION", set_3vector(1000, 900, 0), size);
    menu->b_quit = set_button
        (all_btn, "   ABANDONNER LA\n\t\t\tLUTTE",
        set_3vector(1450, 900, 0), size);
    menu->settings = init_settings(all_btn, wd->splash);
    return menu->menu_l && menu->b_resume && menu->b_start &&
        menu->b_settings && menu->b_quit && menu->settings;
}

menu_t* init_menu(window_t* wd, list_button_t** all_btn)
{
    const bool status = wd && all_btn;
    menu_t* menu = malloc(sizeof(menu_t));

    if (!status || !init_menu_impl(wd, all_btn, menu)) {
        free_menu(menu);
        return NULL;
    }
    menu->settings->other = NULL;
    if (!append_btn_menu(wd, menu)) {
        free_menu(menu);
        menu = NULL;
    }
    return menu;
}
