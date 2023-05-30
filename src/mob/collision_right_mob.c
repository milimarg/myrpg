/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** collision_right_mob
*/

#include "../../include/my_rpg/my_rpg.h"

static void else_two(sfVector2f *mob_pos, mob_t *mob, sfImage *image,
sfVector2f view_center)
{
    int collision_mob = 0;

    for (int i = 0; i < 20; i++)
        collision_mob = collision_up(mob_pos, mob, image, i);
    if (!collision_mob) {
        (*mob_pos).y -= mob->mob_speed_tavern;
        if ((*mob_pos).y < view_center.y + 2.0
        && (*mob_pos).y > view_center.y - 2)
            mob->count = 1;
        else
            mob->count = 4;
    } else
        mob->count = 1;
}

static void change_count(sfVector2f *mob_pos, sfVector2f view_center,
mob_t  *mob)
{
    if ((*mob_pos).x < view_center.x + 2.0
    && (*mob_pos).x > view_center.x - 2.0)
        mob->count = 1;
    if (view_center.x < (*mob_pos).x)
        mob->count = 1;
}

static int collision_right(sfVector2f *mob_pos, mob_t *mob, sfImage *image,
int i)
{
    int collision_mob = 0;

    for (int j = 0; j < 36; j++)
        if (sfColor_toInteger(sfImage_getPixel(image, (int)((*mob_pos).x) + i,
        (int)((*mob_pos).y - 18) + j)) == sfColor_toInteger(sfRed))
            collision_mob = 1;
    return collision_mob;
}

void update_mob_tavern_right(sfVector2f *mob_pos, game_t *game, mob_t *mob,
sfImage *image)
{
    int collision_mob = 0;
    sfVector2f view_center = sfView_getCenter(game->win->view);

    if (view_center.x > (*mob_pos).x && !((*mob_pos).x <= view_center.x
    + 2.0 && (*mob_pos).x >= view_center.x - 2.0) &&
    (mob->count == 0 || mob->count == 2 || mob->count == 4)) {
        for (int i = 0; i < 20; i++)
            collision_mob = collision_right(mob_pos, mob, image, i);
        if (!collision_mob) {
            mob->count = 4;
            (*mob_pos).x += mob->mob_speed_tavern;
            mob->entity_mob = mob->move_mob->run_mob_right;
            mob->move_mob->is_right = 1;
            change_count(mob_pos, view_center, mob);
        } else
            else_two(mob_pos, mob, image, view_center);
    }
}
