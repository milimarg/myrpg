/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** button_functions_keys.c
*/

#include "../../../../include/my_rpg/my_rpg.h"

void button_key_forward(void *data)
{
    game_t *game = data;

    game->pick_up_mode_settings = 1;
    game->pick_up_index = 0;
}

void button_key_back(void *data)
{
    game_t *game = data;

    game->pick_up_mode_settings = 1;
    game->pick_up_index = 1;
}

void button_key_left(void *data)
{
    game_t *game = data;

    game->pick_up_mode_settings = 1;
    game->pick_up_index = 2;
}

void button_key_right(void *data)
{
    game_t *game = data;

    game->pick_up_mode_settings = 1;
    game->pick_up_index = 3;
}
