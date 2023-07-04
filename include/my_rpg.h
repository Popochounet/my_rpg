/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** header for MY_RPG project
*/

#ifndef MY_RPG_H
    #define MY_RPG_H

    #include <rpg_types.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>

    #include <my_graphics.h>
    #include <audio.h>

    #include <SFML/Audio.h>
    #include <crowd.h>
    #include <math.h>

    #include <speech_bubble.h>
    #include <characters.h>
    #include <countryball.h>
    #include <button_simple.h>
    #include <my_macros.h>
    #include <my.h>

    #define NB_ALLIED_REQUIRED 30

    extern const char *const SAVE_PATH;
    extern const char *const INDICATOR_SAVE_LOAD_BUTTON;
    extern const char *const INDICATORS_STATS_INVENTORY_BUTTON;

    typedef enum {
        STAT_LVL,
        STAT_EXP,
        STAT_DMG,
        STAT_HP,
        STAT_SPD,
        STAT_DEF,
        STAT_MAX
    } stat_list_t;

    #define SF_GREY sfColor_fromRGBA(200, 200, 200, 100)

    typedef enum {
        SAVE_FILE_EXISTS,
        SAVE_FILE_DOESNT_EXIST,
        SAVE_FILE_ERROR
    } save_file_state_t;

    typedef struct interface_s {
        draw_t** stat_name;
        draw_t** stat_nb;
        char *stat_values[STAT_MAX];
        button_s_t** stat_btns;
    } interface_t;

    typedef struct menu_cat_s {
        draw_t** title;
        button_s_t** btn;
        sliding_button_t** s_btn;
        draw_t* bg;
        layer_t* menu_cat_l;
        void** other;
    } menu_cat_t;

    typedef struct menu_s {
        button_s_t* b_start;
        button_s_t* b_settings;
        button_s_t* b_quit;
        button_s_t* b_resume;
        menu_cat_t* settings;
        layer_t* bg_l;
        layer_t* menu_l;
        sfBool show;
    } menu_t;

    typedef struct pause_s {
        button_s_t* b_resume;
        button_s_t* b_menu;
        button_s_t* b_save;
        button_s_t* b_load;
        button_s_t* b_settings;
        button_s_t* b_quit;
        button_s_t* b_player;
        menu_cat_t* settings;
        menu_cat_t* player;
        layer_t* pause_l;
        sfBool show;
    } pause_t;

    typedef struct game_s {
        pause_t* pause_menu;
        crowd_t *crowd;
        interface_t* stat_ui;
        list_bubble_t* list_bubbles;
        weapon_t** all_weapons;
        layer_t *layer_fx;
    } game_t;

    typedef struct game_src_s {
        menu_t* menu;
        game_t* game;
        list_button_t* all_btn;
        audio_t audio;
        bool tuto;
    } game_src_t;

    void edit_hitbox(window_t * wd);
    game_src_t* init_game_sources(window_t* wd);
    void tuto(window_t* wd, game_src_t* g_src);

    void menu(window_t* wd, game_src_t* g_src);
    void core(window_t** wd, game_src_t** g_src);
    void pause_menu(window_t* wd, game_src_t* g_src);
    void save_and_load(game_src_t* g_src);

    void init_stat(stat_t *stat, stat_t* base, character_type_t type);
    menu_cat_t* init_management(window_t* wd, list_button_t** a_btns);
    player_t *init_player(window_t* wd, game_t *game, bool resume);
    sfTexture *init_player_text(character_type_t type);
    bool init_crowd
        (window_t* wd, list_button_t** a_btn, game_src_t* g_src, bool resume);

    void init_stat_ui_values(interface_t *stat_ui);
    void update_stat_ui(stat_t stat, interface_t* stat_ui);
    void update_stat(stat_t *stat, int type, interface_t* stat_ui);

    interface_t* init_p_man_inventory(layer_t* lyr, list_button_t** a_btn);
    interface_t* init_stat_interface(layer_t* ui, list_button_t** a_btn);
    draw_t** init_weapon_sprite(layer_t* lyr, bool pause);
    weapon_t** init_all_weapons(void);
    button_s_t* init_stat_interface_bis
        (int i, list_button_t** a_btn, layer_t* ui);
    void update_weapon_ui
        (weapon_t** all_weapons, player_t* player, interface_t* inv_ui);
    void weapon_interaction_p_man
        (weapon_t** all_weapons, player_t* player, interface_t* inv_ui);
    weapon_t* select_weapon
        (weapon_t** all_weapons, weapon_t* current, int dir);


    void stat_interaction(stat_t* stat, interface_t* stat_ui);
    void stat_interaction_p_man
        (stat_t* stat, stat_t base, interface_t* stat_ui);
    void player_management_core(window_t* wd, game_src_t* g_src,
        menu_cat_t* p_man);
    void settings_core
    (window_t* wd, game_src_t* g_src,
        button_s_t* set_btn, layer_t* layer_to_switch);

    menu_t* init_menu(window_t* wd, list_button_t** all_btn);
    menu_cat_t* init_settings(list_button_t** all_btn, layer_t* spl);
    pause_t* init_pause_menu
        (window_t* wd, list_button_t** btns, game_src_t* g_src);

    inv_slot_t* init_inventory(window_t *wd, int nb_slots);
    character_t* init_character(window_t* wd);
    void change_slot_selected
        (character_t* charac, sfMouseWheelScrollEvent evt, game_src_t* g_src);

    save_file_state_t does_save_file_exist(void);
    bool save_to_file(player_t *player);
    bool load_from_file(player_t *player);
    void refresh_player
        (player_t* player, sprite_t* player_sprite, game_t* game);

    void sliding_button_moved(list_button_t* all_btn, sfMouseMoveEvent evt);
    void button_pressed
        (window_t* wd, list_button_t* all_btn,
        sfMouseButtonEvent evt, game_src_t* g_src);

    void mouse_moved(sfMouseMoveEvent evt, game_src_t* g_src);
    void analyse_events
        (window_t* wd, sfEvent event, game_src_t *g_src);
    void mouse_button_pressed
        (window_t* wd, sfMouseButtonEvent evt, game_src_t* g_src);
    void mouse_button_released
        (sfRenderWindow* wd, sfMouseButtonEvent evt, list_button_t* all_btn);

    layer_t* init_background(void);
    menu_t* init_menu(window_t* wd, list_button_t** all_btn);

    void change_mouse_from_resolution(sfEvent* evt, sfVector2f size);
    void change_resolution(window_t* wd, sfVector2f size);
    void resolutions(window_t* wd, menu_cat_t* settings);

    void free_menu(menu_t *menu);
    void free_g_src(game_src_t* g_src);
    void free_main(window_t *window, game_src_t *g_src);
    void free_weapon_sprite(draw_t **weapon);
    void free_single_cop(cop_t **cop);

    void restart(window_t** wd, game_src_t** g_src);

    void win_pop_up(void);

#endif
