/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

void init_end_action(game_t *game)
{
    sfVector2u miam = sfRenderWindow_getSize(game->win->renderer);

    update_scene_coord_pos(game, 0.0, 0.0);
    sfView_reset(game->win->view, (sfFloatRect){0, 0, miam.x, miam.y});
    game->current_scene->can_player_move = sfFalse;
    sfRenderWindow_setMouseCursorVisible(game->win->renderer, sfFalse);
}
