/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

void init_jewels_room(game_t *game)
{
    my_entity *stand = spawn_entity(game->textures_list, "stand", 0);
    npc_t *guard = (npc_t *)find_in_object_list(game,
    "capture_guard")->struct_type;
    npc_t *guard2 = (npc_t *)find_in_object_list(game,
    "capture_guard_2")->struct_type;

    sfSprite_setScale(guard->entity->anim->sprite, (sfVector2f){5.6, 5.6});
    sfSprite_setScale(guard2->entity->anim->sprite, (sfVector2f){5.6, 5.6});
    sfSprite_setScale(game->player->entity->anim->sprite,
    (sfVector2f){0.45, 0.45});
    set_spawnpoint(stand, &(sfVector2f){650, 455}, 0);
    sfSprite_setScale(stand->anim->sprite, (sfVector2f){0.075, 0.075});
    add_to_object_list_after_map(game, init_object(stand, ENTITY, "stand"),
    ENTITY);
    add_ui_to_list(game);
}
