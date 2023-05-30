/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

void init_main_map_night_action(game_t *game)
{
    sfRenderWindow_setMouseCursorVisible(game->win->renderer, sfFalse);
    sfSprite_setScale(game->player->entity->anim->sprite,
    (sfVector2f){0.09, 0.09});
    game->current_scene->can_player_move = sfTrue;
    sfView_reset(game->win->view, (sfFloatRect){0, 0, 1920, 1080});
    sfView_zoom(game->win->view, 0.25);
    sfView_setCenter(game->win->view, (sfVector2f){1645, 1090});
    sfRenderWindow_setView(game->win->renderer, game->win->view);
    if (game->have_to_reset_view)
        set_view_to_coord_pos(game);
}
