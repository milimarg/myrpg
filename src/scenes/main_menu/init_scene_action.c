/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

void init_main_menu_action(game_t *game)
{
    game->current_scene->can_player_move = sfFalse;
    sfRenderWindow_setMouseCursorVisible(game->win->renderer, sfTrue);
    sfView_reset(game->win->view, (sfFloatRect){0, 0, 1920, 1080});
    sfView_setSize(game->win->view, (sfVector2f){1920, 1080});
    sfView_setCenter(game->win->view,
    (sfVector2f){(float)sfRenderWindow_getSize(game->win->renderer).x / 2,
    (float)sfRenderWindow_getSize(game->win->renderer).y / 2});
    sfView_zoom(game->win->view, 0.35);
    if (game->have_to_reset_view)
        set_view_to_coord_pos(game);
}
