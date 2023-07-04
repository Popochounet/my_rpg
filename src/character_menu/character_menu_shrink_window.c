/*
** EPITECH PROJECT, 2023
** shrink_window.c
** File description:
** -> Shrinks character menu window
*/

#include <button.h>
#include <character_menu.h>

const float DESCRIPTION_Y_OFFSET = 250.f;

static sfVector2u character_menu_get_minimal_window
(button_t *bottom_right_button)
{
    sfText *const button_text = bottom_right_button->text;
    sfFloatRect *const rect = &bottom_right_button->area;
    const sfFloatRect title_size = sfText_getGlobalBounds(button_text);
    const button_title_pos_t title_pos = bottom_right_button->title_pos;
    sfVector2u minimal_size = {
        .x = rect->left + rect->width,
        .y = rect->top + rect->height
    };

    if (rect->height < title_size.height) {
        minimal_size.y += title_size.height - rect->height;
    }
    if (rect->width < title_size.width) {
        minimal_size.x += title_size.width - rect->width;
    }
    if (title_pos == BUTTON_TITLE_BENEATH || title_pos == BUTTON_TITLE_ABOVE) {
        minimal_size.y += bottom_right_button->text_size;
    }
    return minimal_size;
}

bool character_menu_shrink_window
(sfRenderWindow *window, button_t *bottom_right_button)
{
    const sfVector2u current_size = sfRenderWindow_getSize(window);
    const sfFloatRect window_rect = {
        .left = 0,
        .top = 0,
        .width = current_size.x,
        .height = current_size.y
    };
    sfView *view = sfView_createFromRect(window_rect);
    sfVector2u minimal_size =
        character_menu_get_minimal_window(bottom_right_button);

    minimal_size.y += DESCRIPTION_Y_OFFSET;
    if (!view) {
        return false;
    }
    sfRenderWindow_setSize(window, minimal_size);
    sfRenderWindow_setView(window, view);
    sfView_destroy(view);
    return true;
}
