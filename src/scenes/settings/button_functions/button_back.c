/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** button_back
*/

#include "../../../../include/my_rpg/my_rpg.h"

void button_back_to_main_menu(void *data)
{
    game_t *game = data;

    switch_scene(game, game->old_scene_type,
    SCENE_TYPE_ID[game->old_scene_type]);
}
