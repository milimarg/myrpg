/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** map_functions
*/

#include "../../../include/my_rpg/my_rpg.h"

void draw_map(void *data, game_t *game)
{
    map_t *map = CAST_MAP(data);

    sfRenderWindow_drawSprite(game->win->renderer, map->sprite, NULL);
}

void update_map(void *data, game_t *game)
{

}

void event_map(void *data, sfEvent Event, game_t *game)
{

}

void destroy_map(void *data, game_t *game)
{

}

void timer_map(void *data, game_t *game)
{

}
