/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

static linked_list_object_t *find_prev_object_in_object_list(game_t *game,
char *id)
{
    linked_list_object_t *object = NULL;

    for (linked_list_object_t *temp = game->current_scene->object_list;
    temp != NULL; temp = temp->next) {
        if (my_strcmp(temp->object->id, id) == 0) {
            return (object);
        }
        object = temp;
    }
    return (NULL);
}

void init_tavern_action_ext(game_t *game)
{
    linked_list_object_t *object = NULL;

    object = find_list_elem_in_object_list(game, "bandit_chief");
    if (object != NULL) {
        find_prev_object_in_object_list(game, "bandit_chief")->next
        = object->next;
        object->object->destroy(game, game);
    }
    for (int i = 0; i < 4; i++) {
        object = find_list_elem_in_object_list(game, "bandit");
        if (object != NULL) {
            find_prev_object_in_object_list(game, "bandit")->next
            = object->next;
            object->object->destroy(game, game);
        }
    }
}

void init_tavern_action(game_t *game)
{
    sfRenderWindow_setMouseCursorVisible(game->win->renderer, sfFalse);
    sfSprite_setScale(game->player->entity->anim->sprite,
    (sfVector2f){0.105, 0.105});
    game->current_scene->can_player_move = sfTrue;
    if (game->have_to_reset_view)
        set_view_to_coord_pos(game);
    if (game->quests->index != 5) {
        init_tavern_action_ext(game);
    }
}
