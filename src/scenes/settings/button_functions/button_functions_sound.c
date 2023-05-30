/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** button_functions.c
*/

#include "../../../../include/my_rpg/my_rpg.h"

void button_sound_decrease(void *data)
{
    game_t *game = data;

    game->sounds->sound_volume -= 5;
    game->sounds->sound_volume = (game->sounds->sound_volume < 0) ?
    0 : game->sounds->sound_volume;
    sfListener_setGlobalVolume(game->sounds->sound_volume);
}

void button_sound_increase(void *data)
{
    game_t *game = data;

    game->sounds->sound_volume += 5;
    game->sounds->sound_volume = (game->sounds->sound_volume > 100) ?
    100 : game->sounds->sound_volume;
    sfListener_setGlobalVolume(game->sounds->sound_volume);
}
