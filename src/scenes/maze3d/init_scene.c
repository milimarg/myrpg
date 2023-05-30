/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

void init_maze3d(game_t *game)
{
    char *filepath = "./data/scenes/maze3d/config/3d_config";
    my_idt1 *world = create_world(filepath, RAW_CONFIG, sfKeyR,
    &(sfVector2f){(double)game->win->width, (double)game->win->height});

    set_ground_and_sky(game->win->renderer, world);
    add_to_object_list(game, init_object(world, MAZE3D_OBJ, "maze3d"),
    MAZE3D_OBJ);
    game->maze_object->steps = 0;
    game->maze_object->display_solution = 0;
    add_ui_to_list(game);
}
