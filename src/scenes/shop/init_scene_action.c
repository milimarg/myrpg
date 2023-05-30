/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

void init_shop_action(game_t *game)
{
    update_scene_coord_pos(game, 0.0, 20.0);
    game->current_scene->can_player_move = sfFalse;
    sfView_reset(game->win->view, (sfFloatRect){0, 0, 809, 455});
    sfRenderWindow_setView(game->win->renderer,
    sfRenderWindow_getDefaultView(game->win->renderer));
    sfRenderWindow_setMouseCursorVisible(game->win->renderer, sfFalse);
}
