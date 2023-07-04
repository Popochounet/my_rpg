/*
** EPITECH PROJECT, 2023
** speech_bubble_text_size.c
** File description:
** -> Resize text for speech bubble
*/

#include <my.h>
#include <my_macros.h>
#include <speech_bubble.h>

static sfVector3f speech_bubble_text_pos
(sfVector2u bubble_size, sfVector2f text_size,
draw_t *text_draw, sfVector3f bubble_position)
{
    return (sfVector3f) {
        .x = bubble_position.x + ABS(bubble_size.x - text_size.x) / 2,
        .y = bubble_position.y + ABS(bubble_size.y - text_size.y) / 2,
        .z = bubble_position.z
    };
}

void speech_bubble_resize_text_and_move
(data_t *text_data, draw_t *text_draw, char *str, sfTexture *bubble_texture)
{
    const sfVector2u texture_size = sfTexture_getSize(bubble_texture);
    const float real_char_size = texture_size.y * 0.85f;
    const float length_related_char_size =
        0.85f * SPEECH_BUBBLE_WIDTH / my_strlen(str) * 2;
    const float char_size = MIN(real_char_size, length_related_char_size);
    const sfVector2f text_size = {
        .x = text_data->size.x,
        .y = char_size
    };
    sfVector3f new_text_pos = { 0, 0, 0 };

    set_size_data(text_data, text_size);
    new_text_pos = speech_bubble_text_pos
        (texture_size, text_size, text_draw, text_data->position);
    set_pos_draw(text_draw, new_text_pos);
}
