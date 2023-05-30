/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** action_player
*/

#include "../../include/my_rpg/my_rpg.h"

void animation_player(game_t *game, int is_moving, sfKeyCode current_key)
{
    if (is_moving && game->player->sprite_steps
    > game->player->sprite_steps_max) {
        game->player->sprite_steps = 0;
        if (current_key == sfKeyLeft)
            update_animation_reverse(game->player->entity->anim);
        else
            update_animation(game->player->entity->anim);
    }
    if (!is_moving && game->player->entity->anim->i != 0) {
        if (current_key == sfKeyLeft)
            reset_entity_animation_reverse(game->player->entity->anim);
        else
            reset_entity_animation(game->player->entity->anim);
    }
}

int reset_annimation(game_t *game, sfKeyCode current_key)
{
    if (game->dialog->run && game->player->entity->anim->i != 0) {
        if (current_key == sfKeyLeft)
            reset_entity_animation_reverse(game->player->entity->anim);
        else
            reset_entity_animation(game->player->entity->anim);
        return 1;
    }
    return 0;
}

void for_one(game_t *game, sfKeyCode *keys, int *keys_pushed, int *i)
{
    for (int j = 0; keys[j] != -1; j++)
        game->player->can_i_move = (keys_pushed[j] && !game->player->can_i_move)
        ? 1 : game->player->can_i_move;
    if ((game->current_scene->type == CASTLE
    || game->current_scene->type == JEWEL_ROOM) && keys[*i] == sfKeyUp)
        (*i)++;
    if ((game->current_scene->type == CASTLE
    || game->current_scene->type == JEWEL_ROOM) && keys[*i] == sfKeyDown)
        (*i)++;
}
