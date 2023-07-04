/*
** EPITECH PROJECT, 2023
** button.c
** File description:
** -> Button implementation in pure CSFML
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <my_macros.h>
#include <my.h>
#include <button.h>
#include <character_menu.h>
#include <my_rpg.h>

const sfUint32 *CHARACTER_DESCRIPTION[N_CHARACTERS] = {
    UTF8(
        "Bébert le Cheminot bosse à la SNCF depuis ses 18 ans.\n"
        "Gréviste de père en fils, la dynastie des Bébert perpétue cette\n"
        "tradition ancestrale avec un savoir-faire\net une application "
        "qui forcent le respect.\n"
        "Manifeste parce qu'une manif sans un Bébert, c'est un déshonneur\n"
        "sur la famille et la Société Nationale des Chômeurs de France."
        ),
    UTF8(
        "Didier le Docteur ne manque pas de travail dans son désert médical.\n"
        "Entre les visites de routine, les accidents domestiques\net les "
        "consultations d'animaux de la ferme\n(parce que oui, c'est ça la "
        "Creuse), il est débordé.\n"
        "Manifeste parce qu'à la Sécu rien ne va plus et qu'il voudrait "
        "avoir\n"
        "des confrères pour l'aider, à moins de 100 kilomètres si possible."
    ),
    UTF8(
        "Albert, Étudiant en Arts, ne sait pas quoi faire plus tard, mais\n"
        "il aimait bien dessiner au collège quand il n'écoutait pas les "
        "cours.\n"
        "En a aussi marre qu'on le prenne pour un flemmard et un chômeur\n"
        "(et oui, la vériré fait mal).\nManifeste pour montrer que quand il "
        "veut, il peut !\nC'est lui et sa bande qui sont chargés de taguer\n"
        "les murs des banques pour dénoncer le capitalisme."
    ),
    UTF8(
        "Théophile, Étudiant à Sciences Po parce que c'est pépère et que\n"
        "bosser est clairement secondaire.\n"
        "Le travail c'est pas son fort, mais râler et\ntrouver des prétextes "
        "bidons pour ne pas en faire une, il connaît.\n"
        "Manifeste parce que ça serait sa matière principale\ndans son emploi "
        "du temps, si toutefois il en avait un."
    ),
    UTF8(
        "Hugues-Henri François Xavier, fils du préfet, aime voir de la baston\n"
        "parce que ça fait \"petit peuple\" et que c'est rigolo.\n"
        "Est entré à l'ENA pour suivre les traces de papa, d'ailleurs\n"
        "c'est lui qui l'a fait rentrer grâce à ses \"relations\".\n"
        "Manifeste pour aller regarder ceux qui ont besoin de travailler,\n"
        "mais s'est fait entraîner au coeur de la manif.\n"
        "Il a beau hurler \"Je suis le fils du préfet\" (comme d'habitude),\n"
        "rien n'y fait (comme d'habitude)."
    ),
    UTF8(
        "René l'Ouvrier, prolétaire depuis toujours, regrette Lénine et le "
        "PCF.\n"
        "Entre les conditions de travail qui se dégradent, le salaire\n"
        "stagnant malgré une inflation démentielle, rien ne va plus !\n"
        "Manifeste parce que l'état est corrompu\net n'a aucune considération "
        "pour le peuple qui se tue au travail."
    ),
    UTF8(
        "#@&~, le Casseur dont on ne doit pas prononcer le nom.\n"
        "Appelé par une multitude de noms, \"le Casseur\" est celui qu'il\n"
        "préfère, sobre mais néanmoins efficace.\nTout comme sa batte de "
        "base-ball ou son marteau.\n"
        "Manifeste même s'il n'est pas beaucoup aprécié.\nSes revendications"
        " sont floues, mais il sera "
        "systématiquement sous\nla lumière des projecteurs !"
    )
};

const char *SPRITES_FILENAMES[N_CHARACTERS][2] = {
    SPRITE_FILENAMES("cheminot"),
    SPRITE_FILENAMES("docteur"),
    SPRITE_FILENAMES("étudiant_en_arts"),
    SPRITE_FILENAMES("étudiant_sciences_po"),
    SPRITE_FILENAMES("fils_du_préfet"),
    SPRITE_FILENAMES("ouvrier"),
    SPRITE_FILENAMES("casseur")
};

const sfUint32 *CHARACTER_NAMES_UTF8[N_CHARACTERS] = {
    UTF8("Le Cheminot"),
    UTF8("Le Docteur"),
    UTF8("L'Étudiant en Arts"),
    UTF8("L'Étudiant de Sciences Po"),
    UTF8("Le Fils du Préfet"),
    UTF8("L'Ouvrier"),
    UTF8("Le Casseur")
};

const char *CHARACTER_NAMES_ANSI[N_CHARACTERS] = {
    "Le Cheminot",
    "Le Docteur",
    "L'Étudiant en Arts",
    "L'Étudiant de Sciences Po",
    "Le Fils du Préfet",
    "L'Ouvrier",
    "Le Casseur"
};

const sfVector2f DESCRIPTION_POSITION = {
    .x = 25.f,
    .y = 100.f
};

static void character_menu_check_sprite_click
(character_menu_t *menu, character_type_t *character)
{
    for (unsigned i = 0; i < N_CHARACTERS; i++) {
        if (!is_mouse_in_rect(menu->window, &menu->buttons[i].area)) {
            continue;
        }
        if (menu->character_selected != i) {
            menu->character_selected = i;
            continue;
        }
        sfRenderWindow_close(menu->window);
        *character = (character_type_t)i;
        break;
    }
}

static void character_menu_handle_events
(character_menu_t *menu, character_type_t *character)
{
    while (sfRenderWindow_pollEvent(menu->window, &menu->event)) {
        switch (menu->event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(menu->window);
            break;
        case sfEvtMouseButtonPressed:
            character_menu_check_sprite_click(menu, character);
            break;
        default:
            break;
        }
    }
}

static bool character_menu_rotate_sprites(character_menu_t *menu)
{
    static bool are_characters_from_behind = false;
    const char *filename = NULL;

    for (unsigned i = 0; i < N_CHARACTERS; i++) {
        filename = SPRITES_FILENAMES[i][are_characters_from_behind];
        if (!button_fill_sprite(&menu->buttons[i], filename)) {
            character_menu_free(menu);
            return false;
        }
    }
    if (sfClock_getElapsedTime(menu->clock).microseconds < 500'000) {
        return true;
    }
    are_characters_from_behind ^= 1;
    sfClock_restart(menu->clock);
    return true;
}

static void character_menu_draw(character_menu_t *menu)
{
    sfText *description = NULL;

    sfRenderWindow_clear(menu->window, sfCyan);
    for (unsigned i = 0; i < N_CHARACTERS; i++) {
        draw_button(menu->window, &menu->buttons[i]);
    }
    if (menu->character_selected < N_CHARACTERS) {
        description = menu->descriptions[menu->character_selected];
        sfRenderWindow_drawText(menu->window, description, NULL);
    }
    sfRenderWindow_display(menu->window);
}

character_type_t select_character(void)
{
    character_menu_t menu;
    character_type_t character = CHARACTER_NONE;

    if (!character_menu_init(&menu)) {
        return CHARACTER_ERROR;
    }
    while (sfRenderWindow_isOpen(menu.window)) {
        sfRenderWindow_setPosition(menu.window, (sfVector2i){540, 500});
        if (!sfRenderWindow_hasFocus(menu.window))
            sfRenderWindow_requestFocus(menu.window);
        character_menu_handle_events(&menu, &character);
        character_menu_draw(&menu);
        character_menu_rotate_sprites(&menu);
        character_menu_shrink_window(menu.window, &BOTTOM_RIGHT_BUTTON(&menu));
    }
    character_menu_free(&menu);
    return character;
}
