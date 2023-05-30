/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** regeneration_player
*/

#include "../../include/my_rpg/my_rpg.h"

static void timer_increase_hp_player(game_t *game)
{
    game->player->regen_timer->hp_elapsed_time =
    sfClock_getElapsedTime(game->win->clock).microseconds / 1000000.0;

    if (game->player->regen_timer->hp_elapsed_time
    - game->player->regen_timer->hp_interval
    >= game->player->regen_timer->hp_defined_limit) {
        game->player->regen_timer->hp_interval
        = game->player->regen_timer->hp_elapsed_time;
        if (game->player->current_hp + 5 >= game->player->stats->hp) {
            game->player->current_hp = game->player->stats->hp;
            update_player_hp_display(game);
        } else {
            game->player->current_hp += 5;
            update_player_hp_display(game);
        }
    }
}

void regeneration_player_hp_ext(game_t *game)
{
    if (game->player->regen_timer->switch_timer == 1) {
        if (game->player->is_attacked) {
            game->player->regen_timer->switch_timer = 0;
            return;
        }
        timer_increase_hp_player(game);
    }
}

void regeneration_player_hp(game_t *game)
{
    game->player->regen_timer->elapsed_time =
    sfClock_getElapsedTime(game->win->clock).microseconds / 1000000.0;

    if (game->player->regen_timer->switch_timer
    == 0 && game->player->regen_timer->elapsed_time -
    game->player->regen_timer->interval
    >= game->player->regen_timer->defined_limit) {
        game->player->regen_timer->interval
        = game->player->regen_timer->elapsed_time;
        if (!(game->player->is_attacked) && game->player->current_hp
        < game->player->stats->hp)
            game->player->regen_timer->switch_timer = 1;
        if (game->player->is_attacked)
            game->player->regen_timer->switch_timer = 0;
    }
    regeneration_player_hp_ext(game);
}
