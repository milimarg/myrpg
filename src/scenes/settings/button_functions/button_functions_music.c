/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** button_functions_music.c
*/

#include "../../../../include/my_rpg/my_rpg.h"

void button_music_decrease(void *data)
{
    game_t *game = data;

    game->sounds->music_volume--;
    game->sounds->music_volume = (game->sounds->music_volume < 0) ?
    0 : game->sounds->music_volume;
}

void button_music_increase(void *data)
{
    game_t *game = data;

    game->sounds->music_volume++;
    game->sounds->music_volume = (game->sounds->music_volume > 100) ?
    100 : game->sounds->music_volume;
}
