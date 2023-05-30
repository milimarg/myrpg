/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** button_functions_screen.c
*/

#include "../../../../include/my_rpg/my_rpg.h"

void button_set_fullscreen(void *data)
{
    game_t *game = data;

    if (!game->fullscreen) {
        game->fullscreen = 1;
        game->window_style = sfFullscreen;
        sfRenderWindow_close(game->win->renderer);
        game->win->renderer = sfRenderWindow_create(game->current_mode,
        game->window_name, game->window_style, NULL);
    }
}

void button_set_windowed(void *data)
{
    game_t *game = data;

    if (game->fullscreen) {
        game->fullscreen = 0;
        game->window_style = sfDefaultStyle;
        sfRenderWindow_close(game->win->renderer);
        game->win->renderer = sfRenderWindow_create(game->current_mode,
        game->window_name, game->window_style, NULL);
    }
}
