/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** main_map_night_functions.c
*/

#include "../../../include/my_rpg/my_rpg.h"

void draw_map_night(void *data, game_t *game)
{
}

void update_map_night(void *data, game_t *game)
{
    main_map_night *night = CAST_MAIN_MAP_NIGHT(data);

    dialog_go_to_next_line(game->dialog, game->win, &night->delay_update_line);
}

void event_map_night(void *data, sfEvent Event, game_t *game)
{

}

void destroy_map_night(void *data, game_t *game)
{

}

void timer_map_night(void *data, game_t *game)
{
    main_map_night *night = CAST_MAIN_MAP_NIGHT(data);

    night->wait_step++;
    if (night->wait_step > night->wait_current_max) {
        if (night->wait_temp) {
            night->wait_temp = 0;
            night->wait_current_max = 1;
            game->dialog->fd =
            fopen("./data/scenes/start_cinematic/text/tuto_move", "r");
            game->dialog->run = 1;
        }
        night->wait_step = 0;
        update_dialog_text(game->dialog, game->sounds->narrator_voice,
        game->win);
    }
}
