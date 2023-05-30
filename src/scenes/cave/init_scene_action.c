/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

void init_cave_action(game_t *game)
{
    game->current_scene->can_player_move = sfTrue;
    sfRenderWindow_setMouseCursorVisible(game->win->renderer, sfFalse);
    sfView_reset(game->win->view, (sfFloatRect){0, 0, 1920, 1080});
    sfView_zoom(game->win->view, 0.25);
    sfView_setCenter(game->win->view, (sfVector2f){370, 420});
    sfRenderWindow_setView(game->win->renderer, game->win->view);
    if (game->have_to_reset_view)
        set_view_to_coord_pos(game);
}
