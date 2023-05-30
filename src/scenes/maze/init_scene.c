/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

void init_maze(game_t *game)
{
    int seconds_delay = 60;

    game->maze_object = malloc(sizeof(maze_object_t));
    game->maze_object->steps = 0;
    game->maze_object->steps_max = (1000 * seconds_delay) / 25;
    game->maze_object->display_solution = 0;
    add_ui_to_list(game);
}
