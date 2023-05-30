/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

void set_scale_flowers(game_t *game)
{
    npc_t *moonbloom1 =
    (npc_t *)(find_in_object_list(game, "moonbloom1")->struct_type);
    npc_t *moonbloom2 =
    (npc_t *)(find_in_object_list(game, "moonbloom2")->struct_type);
    npc_t *moonbloom3 =
    (npc_t *)(find_in_object_list(game, "moonbloom3")->struct_type);

    sfSprite_setScale(moonbloom1->entity->anim->sprite,
    (sfVector2f){0.5, 0.5});
    sfSprite_setScale(moonbloom2->entity->anim->sprite,
    (sfVector2f){0.5, 0.5});
    sfSprite_setScale(moonbloom3->entity->anim->sprite,
    (sfVector2f){0.5, 0.5});
}

void init_main_map_action(game_t *game)
{
    sfRenderWindow_setMouseCursorVisible(game->win->renderer, sfFalse);
    set_scale_flowers(game);
    sfSprite_setScale(game->player->entity->anim->sprite,
    (sfVector2f){0.09, 0.09});
    game->current_scene->can_player_move = sfTrue;
    sfView_reset(game->win->view, (sfFloatRect){0, 0, 1920, 1080});
    sfView_zoom(game->win->view, 0.25);
    sfView_setCenter(game->win->view, (sfVector2f){680, 850});
    sfRenderWindow_setView(game->win->renderer, game->win->view);
    if (game->have_to_reset_view)
        set_view_to_coord_pos(game);
}
