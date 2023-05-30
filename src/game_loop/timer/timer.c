/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** timer
*/

#include "../../../include/my_rpg/my_rpg.h"
#include "../../../include/scenes/jewels_room/prototype.h"

void set_timer_maze2d_loop(game_t *game)
{
    map_t *map = NULL;

        for (linked_list_object_t *list = game->current_scene->object_list;
        list != NULL; list = list->next) {
            if (list->object->type == MAP) {
                map = (map_t *)list->object->struct_type;
                map->texture = find_texture_in_list(game->textures_list,
                "2d_maze_solved")->texture;
                sfSprite_setTexture(map->sprite, map->texture, sfTrue);
            }
        }
}

void set_timer_maze2d(game_t *game)
{
    if (game->maze_object->steps > game->maze_object->steps_max &&
        !game->maze_object->display_solution) {
        game->maze_object->display_solution = 1;
        set_timer_maze2d_loop(game);
    }
}

void timer(game_t *game)
{
    for (linked_list_object_t *list = game->current_scene->object_list;
    list != NULL; list = list->next) {
        list->object->timer(list->object->struct_type, game);
        if (game->current_scene->type == JEWEL_ROOM) {
            timer_jewels_room(list->object->struct_type, game);
        }
        if (game->current_scene->type == MAZE) {
            set_timer_maze2d(game);
            game->maze_object->steps++;
        }
        if (game->current_scene->type == THRONE_ROOM) {
            timer_throne_room(list->object->struct_type, game);
        }
    }
}
