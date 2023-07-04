/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** crowd.h
*/

#ifndef CROWD
    #define CROWD

    #include <rpg_types.h>
    #include <rpg_types.h>
    #include <my_graphics.h>
    #include <my_rpg.h>
    #include <characters.h>
    #include <character_menu.h>

    #define CROWD_SIZE 200
    #define MAX_SPRITES 25
    #define WD_WIDTH 1920
    #define WD_HEIGHT 1080
    #define MAX_SPEED 0.05f

    #define NB_STAT 6
    #define NB_WEAPON 3

    typedef struct progress_bar_s {
        draw_t *fill;
        sfFloatRect area;
    } progress_bar_t;

    /*
        Don't change the order !
    */
    typedef enum dir_cop {
        DIR_COP_N,
        DIR_COP_NE,
        DIR_COP_E,
        DIR_COP_SE,
        DIR_COP_S,
        DIR_COP_SW,
        DIR_COP_W,
        DIR_COP_NW,
        DIR_COP_MAX,
        DIR_COP_DEFAULT = DIR_COP_S
    } dir_cop_e;

    typedef enum dir_e {
        DIR_PLAYER_UP,
        DIR_PLAYER_DOWN
    } dir_e;

    extern const sfIntRect COP_SPRITESHEET_RECTS[DIR_COP_MAX];

    struct interface_s;

    typedef struct {
        sfVector2f size_hitbox;
        float dmg;
        float cooldown;
        float knockback;
    } weapon_t;

    typedef struct stat_s {
        float damage;
        float hp;
        float speed;
        float defense;
        int level;
        int exp_point;
    } stat_t;

    typedef struct cop_s {
        sfClock *clock;
        draw_t *draw;
        stat_t stat;
        progress_bar_t hp;
        bool dead;
        dir_cop_e cop_e;
    } cop_t;

    typedef enum in_mob_e {
        OUT,
        IN,
        DEAD
    } in_mob_e;

    typedef struct mob_s {
        draw_t *draw;
        in_mob_e in_mob;
        int dir;
        dir_e mov;
        character_type_t type;
    } mob_t;

    typedef struct player_s {
        sfClock *clock;
        draw_t *draw;
        stat_t stat;
        stat_t base;
        progress_bar_t hp;
        progress_bar_t exp;
        draw_t *range;
        draw_t *cooldown;
        draw_t **weapon_draw;
        character_type_t type;
        weapon_t* weapon;
        dir_e dir;
        int nb_allied;
    } player_t;

    typedef struct crowd_s {
        cop_t **cop;
        mob_t **mob;
        cop_t *boss;
        player_t *player;
    } crowd_t;

    /*progress_bar.c*/
    sfBool draw_within_thr(draw_t *player, draw_t *crowd, float thr);
    void draw_progress_bar(sfRenderWindow *window, progress_bar_t *bar);
    void compute_fill_area(progress_bar_t *bar);
    void set_position_and_size_with_float_rect
    (sfRectangleShape *shape, sfFloatRect *rect);

    /*init_crowd.c*/
    mob_t **init_crowd_mob(window_t* wd);
    void init_progress_bar
    (window_t *window, progress_bar_t *bar, data_t *data, shape_t *shape);
    cop_t **init_crowd_cop(window_t* wd);
    draw_t *init_player_draw(character_type_t type, data_t *data);
    /*rand.c*/

    sfVector2f get_random_position(window_t *wd);
    sfTexture* rand_skin(character_type_t *type);
    bool check_pos(draw_t *draw, window_t *wd);
    void attack(crowd_t *crowd);
    /*update.c*/

    void update(crowd_t *crowd, window_t *wd);
    float rand_move(void);
    void update_mob(mob_t *mob, crowd_t *crowd, sfVector2f move, window_t *wd);
    void update_cop(cop_t *cop, crowd_t *crowd, sfVector3f spritePosition);
    void get_sprt_cop(draw_t *draw, sfVector2f move, dir_cop_e *dir);
    void get_sprt_boss(draw_t *draw, sfVector2f move, dir_cop_e *dir);

    /**/
    void move_range
    (player_t *player, sfVector2f move, weapon_t *weapon);
    void knock_back(cop_t *cop, player_t *player, float pw, crowd_t* crowd);
    sfVector3f calc_dist(draw_t *draw1, draw_t *draw2);
    void manage_event(sfRenderWindow* window, sfEvent event, player_t *player);
    void free_crowd(crowd_t *crowd);
    sfBool check_collision(draw_t *player, draw_t *crowd);
    void display_crowd(sfRenderWindow *window, crowd_t *crowd);
    void set_anim_mob(draw_t *draw, sfVector2f move, dir_e *dir);
    void crowd
        (window_t* wd, crowd_t *crowd, interface_t* stat_ui, audio_t audio);

#endif /* CROWD_T */
