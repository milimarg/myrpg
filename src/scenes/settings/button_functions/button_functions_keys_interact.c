/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** button_functions_keys_interact.c
*/

#include "../../../../include/my_rpg/my_rpg.h"

void button_key_inventory(void *data)
{
    game_t *game = data;

    game->pick_up_mode_settings = 1;
    game->pick_up_index = 4;
}

void button_key_attack(void *data)
{
    game_t *game = data;

    game->pick_up_mode_settings = 1;
    game->pick_up_index = 5;
}

void button_key_interact(void *data)
{
    game_t *game = data;

    game->pick_up_mode_settings = 1;
    game->pick_up_index = 6;
}
