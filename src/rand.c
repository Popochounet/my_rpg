/*
** EPITECH PROJECT, 2022
** My_rpg_tmp
** File description:
** rand.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

sfTexture* rand_skin(character_type_t *type)
{
    char buff[256] = "images/spritesheets/";
    switch (rand() % 7) {
        case 0: mystrcat(buff,"cheminot_spritesheet");
        *type = CHARACTER_RAILWAY_WORKER; break;
        case 1: mystrcat(buff,"étudiant_en_arts_spritesheet");
        *type = CHARACTER_ART_STUDENT; break;
        case 2: mystrcat(buff,"étudiant_sciences_po_spritesheet");
        *type = CHARACTER_POLITICS_STUDENT; break;
        case 3: mystrcat(buff, "fils_du_préfet_spritesheet");
        *type = CHARACTER_PREFECT_SON; break;
        case 4: mystrcat(buff, "ouvrier_spritesheet");
        *type = CHARACTER_WORKER; break;
        case 5: mystrcat(buff, "casseur_spritesheet");
        *type = CHARACTER_TROUBLEMAKER; break;
        case 6: mystrcat(buff, "docteur_spritesheet");
        *type = CHARACTER_DOCTOR; break;
    }
    mystrcat(buff, ".png");
    sfTexture* text = sfTexture_createFromFile(buff, NULL);
    return text;
}

sfVector2f get_random_position(window_t *wd)
{
    sfVector2f position;
    position.x = (float)(rand() % ((int)wd->map_size.x));
    position.y = (float)(rand() % ((int)wd->map_size.y / 2) +
    (int)wd->map_size.y / 4);
    return position;
}

float rand_move(void)
{
    float move = 0.0f;
    if (rand() % 5 == 0)
        switch (rand() % 3 - 1) {
            case 1: move = 0.05f; break;
            case 0: move = 0.00f; break;
            case -1: move = -0.05f; break;
        }
    return move;
}
