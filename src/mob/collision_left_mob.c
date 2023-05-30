/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** collision_left_mob
*/

#include "../../include/my_rpg/my_rpg.h"

static void change_count(sfVector2f *mob_pos, sfVector2f view_center,
mob_t  *mob)
{
    if ((*mob_pos).x < view_center.x + 2.0
    && (*mob_pos).x > view_center.x - 2.0)
        mob->count = 1;
    if (view_center.x > (*mob_pos).x)
        mob->count = 1;
}

static int collision_left(sfVector2f *mob_pos, mob_t *mob, sfImage *image,
int i)
{
    int collision_mob = 0;

    for (int j = 0; j < 36; j++)
        if (sfColor_toInteger(sfImage_getPixel(image, (int)((*mob_pos).x) - i,
        (int)((*mob_pos).y - 18) + j)) == sfColor_toInteger(sfRed))
            collision_mob = 1;
    return collision_mob;
}

void update_mob_tavern_left(sfVector2f *mob_pos, game_t *game, mob_t *mob,
sfImage *image)
{
    int collision_mob = 0;
    sfVector2f view_center = sfView_getCenter(game->win->view);

    if (view_center.x < (*mob_pos).x && !((*mob_pos).x
    <= view_center.x + 2.0 && (*mob_pos).x >= view_center.x - 2.0)
    && (mob->count == 0 || mob->count == 2 || mob->count == 3)) {
        for (int i = 0; i < 20; i++)
            collision_mob = collision_left(mob_pos, mob, image,  i);
        if (!collision_mob) {
            mob->count = 3;
            (*mob_pos).x -= mob->mob_speed_tavern;
            mob->entity_mob = mob->move_mob->run_mob_left;
            mob->move_mob->is_right = 0;
            change_count(mob_pos, view_center, mob);
        } else
            mob->count = 1;
    }
}
