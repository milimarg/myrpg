/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"
#include "../../../include/scenes/start_cinematic/struct.h"

void init_start_cimenatic_ext(game_t *game, start_cinematic_object *start)
{
    object_t *object = NULL;
    sfVector2f fade_in_size = {game->win->width, game->win->height};

    sfRectangleShape_setSize(start->fade_in, fade_in_size);
    sfRectangleShape_setFillColor(start->fade_in, start->color);
    sfRectangleShape_setOutlineThickness(start->fade_in, 0);
    start->display_fade_in = 1;
    start->display_dialog = 0;
    object = init_object(start, START_CINEMATIC_OBJECT,
    "start_cinematic_object");
    add_to_object_list(game, object, START_CINEMATIC_OBJECT);
}

void init_start_cinematic_values(game_t *game, start_cinematic_object *start)
{
    start->fade_in = sfRectangleShape_create();
    start->color = (sfColor){0, 0, 0, 0};
    start->ms_delay = 25;
    start->delay_update_char = 0;
    start->delay_update_line = 0;
    start->wait_steps = 0;
    start->wait_ms_delay =
    (double)game->dialog->ms_wait_delay / (double)game->clock_delay;

}

void init_start_cinematic(game_t *game)
{
    start_cinematic_object *start = malloc(sizeof(start_cinematic_object));
    sfImage *bg_map_temp = NULL;

    set_dialog_mode(game->dialog, CINEMATIC);
    init_start_cinematic_values(game, start);
    init_start_cimenatic_ext(game, start);
    bg_map_temp = take_screenshot(game->win->renderer);
    start->map_cache_texture = sfTexture_createFromImage(bg_map_temp, NULL);
    start->map_cache = sfSprite_create();
    sfSprite_setTexture(start->map_cache, start->map_cache_texture, sfTrue);
}
