/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** set_player_position
*/

#include "../../../include/my_rpg/my_rpg.h"

void set_player_position_ext(game_t *game, linked_list_object_t *list)
{
    if (game->current_scene->type
    != CASTLE && game->current_scene->type != JEWEL_ROOM)
        sfSprite_setPosition(game->player->entity->anim->sprite,
        sfView_getCenter(game->win->view));
    else
        sfSprite_setPosition(game->player->entity->anim->sprite,
        (sfVector2f){sfView_getCenter(game->win->view).x,
        sfView_getCenter(game->win->view).y + 150});
    sfRenderWindow_drawSprite(game->win->renderer,
    game->player->entity->anim->sprite, NULL);
}

void set_player_position(game_t *game, linked_list_object_t *list)
{
    if (game->current_scene->can_player_move == sfTrue) {
        if (my_strcmp(list->object->id, "map") == 0) {
            set_player_position_ext(game, list);
        }
    }
}
