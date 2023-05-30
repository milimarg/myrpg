/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** button_kinds
*/

#include "../../../../include/my_rpg/my_rpg.h"

void button_back_to_game(void *data)
{
    game_t *game = (game_t *)data;
    pause_object *pause =
    (pause_object *)(find_in_object_list(game, "pause_object")->struct_type);

    switch_scene(game, pause->previous_scene,
    SCENE_TYPE_ID[pause->previous_scene]);
}

void button_inventory(void *data)
{
    game_t *game = (game_t *)data;

    switch_scene(game, INVENTORY, "inventory");
}

void button_save(void *data)
{
    game_t *game = (game_t *)data;

    save(game);
}

void button_load(void *data)
{
    game_t *game = (game_t *)data;

    if (game->already_saved)
        load_save(game);
}
