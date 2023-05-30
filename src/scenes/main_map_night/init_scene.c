/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

void init_main_map_night_ext(game_t *game, main_map_night *night)
{
    night->wait_step = 0;
    night->wait_step_max = 40;
    night->wait_current_max = night->wait_step_max;
    night->delay_update_line = 0;
    night->wait_temp = 1;
    add_to_object_list(game, init_object(night, MAIN_MAP_NIGHT_OBJECT,
    "main_map_night_object"), MAIN_MAP_NIGHT_OBJECT);
    sfVector2f pos = sfRectangleShape_getPosition(game->dialog->gui);
    sfVector2f size = sfRectangleShape_getSize(game->dialog->gui);
    sfVector2u win_size = sfRenderWindow_getSize(game->win->renderer);
    float thickness = sfRectangleShape_getOutlineThickness(game->dialog->gui);
    sfRectangleShape_move(game->dialog->gui,
    (sfVector2f){0, win_size.y - (size.y + pos.y + thickness)});
    sfText_move(game->dialog->text,
    (sfVector2f){0, win_size.y - (size.y + pos.y)});
    set_dialog_mode(game->dialog, DISCUSSION);
    set_triangle_visibility(game->dialog, 1);
    sfSound_setVolume(game->sounds->narrator_voice, 50);
}

void init_main_map_night(game_t *game)
{
    main_map_night *night = malloc(sizeof(main_map_night));

    init_main_map_night_ext(game, night);
    add_ui_to_list(game);
}
