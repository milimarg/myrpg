/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** collision_mob
*/

#include "../../include/my_rpg/my_rpg.h"

int collision_up(sfVector2f *mob_pos, mob_t *mob, sfImage *image, int i)
{
    int collision_mob = 0;

    for (int j = 0; j < 20; j++)
        if (sfColor_toInteger(sfImage_getPixel(image, (int)((*mob_pos).x - 10)
        + j, (int)((*mob_pos).y) - i)) == sfColor_toInteger(sfRed))
                collision_mob = 1;
    return collision_mob;
}

void update_mob_tavern_up(sfVector2f *mob_pos, game_t *game, mob_t *mob,
sfImage *image)
{
    int collision_mob = 0;
    sfVector2f view_center = sfView_getCenter(game->win->view);

    if (view_center.y < (*mob_pos).y && mob->count == 0 && !((*mob_pos).y
    <= view_center.y + 2.0 && (*mob_pos).y >= view_center.y - 2.0)) {
        for (int i = 0; i < 20; i++)
            collision_mob = collision_up(mob_pos, mob, image, i);
        mob->count = 1;
        if (!collision_mob)
            (*mob_pos).y -= mob->mob_speed_tavern;
        else
            mob->count = 2;
    }
}

static int collision_down(sfVector2f *mob_pos, mob_t *mob, sfImage *image,
int i)
{
    int collision_mob = 0;

    for (int j = 0; j < 20; j++)
        if (sfColor_toInteger(sfImage_getPixel(image, (int)((*mob_pos).x - 10)
        + j, (int)((*mob_pos).y) + i)) == sfColor_toInteger(sfRed))
                collision_mob = 1;
    return collision_mob;
}

void update_mob_tavern_down(sfVector2f *mob_pos, game_t *game, mob_t *mob,
sfImage *image)
{
    int collision_mob = 0;
    sfVector2f view_center = sfView_getCenter(game->win->view);

    if (view_center.y > (*mob_pos).y && mob->count == 0 && !((*mob_pos).y
    <= view_center.y + 2.0 && (*mob_pos).y >= view_center.y - 2.0)) {
        for (int i = 0; i < 20; i++)
                collision_mob = collision_down(mob_pos, mob, image, i);
        mob->count = 1;
        if (!collision_mob)
            (*mob_pos).y += mob->mob_speed_tavern;
        else
            mob->count = 2;
    }
}
