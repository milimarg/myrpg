/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** button_kinds
*/

#include "../../../../include/my_rpg/my_rpg.h"

void button_settings(void *data)
{
    game_t *game = data;

    switch_scene(game, SETTINGS, "settings");
}

void button_exit(void *data)
{
    game_t *game = data;

    switch_scene(game, MAIN_MAP, "main_map");
    game->end = sfTrue;
}

void button_continue(void *data)
{
    game_t *game = data;

    if (game->already_saved)
        load_save(game);
}

void button_start(void *data)
{
    game_t *game = (game_t *)data;

    switch_scene(game, START_CINEMATIC, "start_cinematic");
}

void button_save_and_quit(void *data)
{
    game_t *game = (game_t *)data;

    save(game);
    switch_scene(game, MAIN_MENU, "main_menu");
}
