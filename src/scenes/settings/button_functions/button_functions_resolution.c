/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** button_functions_resolution.c
*/

#include "../../../../include/my_rpg/my_rpg.h"

void button_resolution1(void *data)
{
    game_t *game = data;
    sfVideoMode mode = {1920, 1080, 32};

    game->current_mode = (sfVideoMode)mode;
    sfRenderWindow_close(game->win->renderer);
    game->win->renderer = sfRenderWindow_create(mode, game->window_name,
    game->window_style, NULL);
}

void button_resolution2(void *data)
{
    game_t *game = data;
    sfVideoMode mode = {1320, 720, 32};

    game->current_mode = (sfVideoMode)mode;
    sfRenderWindow_close(game->win->renderer);
    game->win->renderer = sfRenderWindow_create(mode, game->window_name,
    game->window_style, NULL);
}
