/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** calculate.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

sfVector3f calculate_repulsion_force(sfVector3f pos1, sfVector3f pos2, float k)
{
    sfVector3f rep;
    float dx = pos2.x - pos1.x;
    float dy = pos2.y - pos2.y;
    float dist_sq = dx * dx + dy * dy;
    float dist = sqrt(dist_sq);
    float force = k / dist_sq;
    rep.x = force * dx / dist;
    rep.y = force * dy / dist;
    return rep;
}

sfVector3f calc_dist(draw_t *draw1, draw_t *draw2)
{
    sfVector3f pos1 = draw1->data->position;
    sfVector3f pos2 = draw2->data->position;
    sfVector2f dir;
        dir.x = pos1.x - pos2.x;
        dir.y = pos1.y - pos2.y;
    float distance = sqrtf(dir.x * dir.x + dir.y * dir.y);
    if (distance > 1.0f) {
        dir.x /= distance;
        dir.y /= distance;
    }
    return set_3vector(dir.x, dir.y, distance);
}
