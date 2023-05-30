/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

void init_throne_room_action(game_t *game)
{
    npc_t *king = (npc_t *)find_in_object_list(game, "king")->struct_type;

    sfRenderWindow_setMouseCursorVisible(game->win->renderer, sfFalse);
    sfView_reset(game->win->view, (sfFloatRect){0, 0, 1920, 1080});
    sfView_zoom(game->win->view, 0.4);
    sfView_setCenter(game->win->view, (sfVector2f){395, 250});
    sfRenderWindow_setView(game->win->renderer, game->win->view);
    sfSprite_setScale(game->player->entity->anim->sprite,
    (sfVector2f){0.12, 0.12});
    sfSprite_setScale(king->entity->anim->sprite,
    (sfVector2f){0.35, 0.35});
    game->current_scene->can_player_move = sfTrue;
    if (game->have_to_reset_view)
        set_view_to_coord_pos(game);
}
