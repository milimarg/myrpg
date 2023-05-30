/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** timer_attack_player
*/

#include "../../include/my_rpg/my_rpg.h"

void timer_attack_player_ext(game_t *game, mob_t *mob)
{
    if (mob->elapsed_time - mob->interval_attacked
    >= mob->attacked_limit && !mob->can_be_attacked) {
        mob->interval_attacked = mob->elapsed_time;
        mob->can_be_attacked = sfTrue;
    }
}

void timer_attack_player(game_t *game, mob_t *mob)
{
    mob->elapsed_time =
    sfClock_getElapsedTime(game->win->clock).microseconds / 1000000.0;
    if (sfKeyboard_isKeyPressed(game->keys[5]) && mob->can_be_attacked) {
        mob->can_be_attacked = sfFalse;
        mob->interval_attacked = mob->elapsed_time;
        if (mob->move_mob->is_right)
            set_entity_animation(game->player->entity->anim,
            "player_attack_r", game->textures_list);
        else
            set_entity_animation(game->player->entity->anim,
            "player_attack_l", game->textures_list);
        update_animation(game->player->entity->anim);
        if (mob->is_attacked) {
            mob->current_hp_mob -= game->player->stats->strength * 5;
        }
    }
    timer_attack_player_ext(game, mob);
}
