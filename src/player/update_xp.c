/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** update_xp
*/

#include "../../include/my_rpg/my_rpg.h"
#include "../../include/my_rpg/player/player.h"

void update_player_xp(game_t *game)
{
    if (game->player->stats->global_xp
    >= XP_FOR_LEVEL[game->player->stats->level]) {
        game->player->stats->stat_point += STAT_POINTS_PER_LEVEL;
        game->player->stats->global_xp
        -= XP_FOR_LEVEL[game->player->stats->level];
        game->player->stats->level += 1;
    }
}
