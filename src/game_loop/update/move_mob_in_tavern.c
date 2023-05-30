/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** move_mob_in_tavern
*/

#include "../../../include/my_rpg/my_rpg.h"

void update_mob_tavern(sfVector2f *mob_pos, game_t *game, mob_t *mob,
sfImage *image)
{
    mob->count = 0;

    (*mob_pos) = sfSprite_getPosition(mob->entity_mob->anim->sprite);
    if (mob->count == 1)
        mob->count = 0;
    update_mob_tavern_up(mob_pos, game, mob, image);
    update_mob_tavern_down(mob_pos, game, mob, image);
    update_mob_tavern_left(mob_pos, game, mob, image);
    update_mob_tavern_right(mob_pos, game, mob, image);
}

void move_sprite_mob_tavern(mob_t *mob, game_t *game)
{
    mob->mob_pos = sfSprite_getPosition(mob->entity_mob->anim->sprite);
    if (mob->mob_pos.x >= sfView_getCenter(game->win->view).x
    - 20 && mob->mob_pos.x <= sfView_getCenter(game->win->view).x + 20
    && mob->mob_pos.y >= sfView_getCenter(game->win->view).y
    - 20 && mob->mob_pos.y <= sfView_getCenter(game->win->view).y + 20) {
        mob->is_attacked = sfTrue;
        game->player->is_attacked = sfTrue;
    } else {
        mob->is_attacked = sfFalse;
        game->player->is_attacked = sfFalse;
        if (mob->entity_mob == mob->move_mob->mob_left
        || mob->entity_mob == mob->move_mob->mob_right)
            reset_entity_animation(mob->entity_mob->anim);
    }
}

void move_mob_tavern(game_t *game, mob_t *mob)
{
    sfImage *image =
    ((map_t *)find_in_object_list(game, "map")->struct_type)->image;
    sfVector2f mob_pos = mob->mob_pos;

    update_mob_tavern(&mob_pos, game, mob, image);
    move_sprite_mob_tavern(mob, game);
    change_mob_side(mob);
    manage_run_mob(game, mob);
    manage_timer_mob(game, mob);
    timer_attack_player(game, mob);
    sfSprite_setPosition(mob->entity_mob->anim->sprite, mob_pos);
}
