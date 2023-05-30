/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

void init_start_cinematic_action(game_t *game)
{
    sfVector2u miam = sfRenderWindow_getSize(game->win->renderer);

    sfRenderWindow_setMouseCursorVisible(game->win->renderer, sfFalse);
    game->current_scene->can_player_move = sfFalse;
    sfRenderWindow_setView(game->win->renderer,
    sfRenderWindow_getDefaultView(game->win->renderer));
    sfView_reset(game->win->view, (sfFloatRect){0, 0, miam.x, miam.y});
    if (game->have_to_reset_view)
        set_view_to_coord_pos(game);
}
