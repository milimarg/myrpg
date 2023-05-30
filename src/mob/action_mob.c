/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** timer_mob
*/

#include "../../include/my_rpg/my_rpg.h"

void change_mob_side(mob_t *mob)
{
    if (mob->is_attacked && !(mob->move_mob->is_right))
        mob->entity_mob = mob->move_mob->mob_right;
    if (mob->is_attacked && mob->move_mob->is_right)
        mob->entity_mob = mob->move_mob->mob_left;
}

void manage_run_mob(game_t *game, mob_t *mob)
{
    mob->run_limit = 0.8;

    mob->elapsed_time = sfClock_getElapsedTime(game->win->clock).microseconds
    / 1000000.0;
    if (mob->elapsed_time - mob->interval_run >= mob->run_limit) {
        mob->interval_run = mob->elapsed_time;
        if (!(mob->is_attacked))
            update_animation(mob->entity_mob->anim);
    }
}

void manage_timer_mob(game_t *game, mob_t *mob)
{
    mob->attack_limit = 0.8;

    mob->elapsed_time = sfClock_getElapsedTime(game->win->clock).microseconds
    / 1000000.0;
    if (mob->mob_can_attack) {
        mob->mob_can_attack = sfFalse;
        mob->interval_attack = mob->elapsed_time;
        update_animation(mob->entity_mob->anim);
        game->player->current_hp -= mob->mob_damage;
        update_player_hp_display(game);
    }
    if (mob->elapsed_time - mob->interval_attack >= mob->attack_limit) {
        mob->interval_attack = mob->elapsed_time;
        if (mob->is_attacked)
            mob->mob_can_attack = sfTrue;
    }
}

void mob_attack(game_t *game, mob_t *mob)
{
    sfSprite_setPosition(game->player->entity->anim->sprite,
    sfView_getCenter(game->win->view));
    if (mob->move_mob->len_move > 3000) {
        remove_head(&mob->move_mob->move_list);
        mob->move_mob->len_move--;
    }
    if (mob->move_mob->len_move > 2999)
        sfSprite_setPosition(mob->entity_mob->anim->sprite,
        (sfVector2f){mob->move_mob->move_list->x,
        mob->move_mob->move_list->y});
    for (link_list_pos_t *temp = mob->move_mob->move_list;
    temp != NULL; temp = temp->next) {
        if (temp->x == mob->mob_pos.x && temp->y == mob->mob_pos.y)
            remove_multiple_node(&temp, temp->x, temp->y);
    }
    if (mob->mob_pos.x == sfView_getCenter(game->win->view).x
    && mob->mob_pos.y == sfView_getCenter(game->win->view).y)
        mob->move_mob->len_move = 0;
}
