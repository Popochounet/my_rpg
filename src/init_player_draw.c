/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** init_player_draw.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

sfTexture *init_player_text(character_type_t type)
{
    char buff[256] = "images/spritesheets/";
    switch (type) {
        case CHARACTER_RAILWAY_WORKER:
            mystrcat(buff,"cheminot_spritesheet"); break;
        case CHARACTER_DOCTOR :
            mystrcat(buff, "docteur_spritesheet"); break;
        case CHARACTER_ART_STUDENT :
            mystrcat(buff,"étudiant_en_arts_spritesheet"); break;
        case CHARACTER_POLITICS_STUDENT :
            mystrcat(buff,"étudiant_sciences_po_spritesheet"); break;
        case CHARACTER_PREFECT_SON :
            mystrcat(buff, "fils_du_préfet_spritesheet"); break;
        case CHARACTER_WORKER :
            mystrcat(buff, "ouvrier_spritesheet"); break;
        case CHARACTER_TROUBLEMAKER :
            mystrcat(buff, "casseur_spritesheet"); break;
        default: break;
    } mystrcat(buff, ".png");
    sfTexture* text = sfTexture_createFromFile(buff, NULL);
    return text;
}

draw_t *init_player_draw(character_type_t type, data_t *data)
{
    sprite_t *sprite = init_sprite();
    sfTexture *texture = init_player_text(type);
    set_texture_sprite(sprite, texture, (sfIntRect) {0, 0, 48, 72});
    return create_draw(sprite, SPRITE, data);
}
