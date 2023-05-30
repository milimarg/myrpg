/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** maze3d_functions
*/

#include "../../../include/my_rpg/my_rpg.h"

void draw_maze3d(void *data, game_t *game)
{

}

void update_maze3d(void *data, game_t *game)
{
    my_idt1 *world = CAST_MAZE3D(data);

    move_player_idt1(world, game);
    if (world->player.x > 90 && world->player.x < 110 &&
    world->player.y > 90 && world->player.y < 110) {
        switch_scene(game, CAVE, "cave");
        sfView_setCenter(game->win->view, (sfVector2f){900, 440});
        set_entity_animation(game->player->entity->anim, "player.down",
        game->textures_list);
    }
}

void event_maze3d(void *data, sfEvent Event, game_t *game)
{

}

void destroy_maze3d(void *data, game_t *game)
{
    my_idt1 *world = CAST_MAZE3D(data);

    destroy_world(world);
}

void timer_maze3d(void *data, game_t *game)
{
    my_idt1 *world = CAST_MAZE3D(data);

    if (game->maze_object->steps > game->maze_object->steps_max &&
    !game->maze_object->display_solution) {
        game->maze_object->display_solution = 1;
        reload_world(world, "./data/scenes/maze3d/config/3d_config_solved",
        RAW_CONFIG, 1);
    }
    game->maze_object->steps++;
    world->move_steps++;
}
