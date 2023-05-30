/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

void init_maze_action(game_t *game)
{
    game->current_scene->can_player_move = sfTrue;
    sfRenderWindow_setMouseCursorVisible(game->win->renderer, sfFalse);
    if (game->have_to_reset_view)
        set_view_to_coord_pos(game);
}
