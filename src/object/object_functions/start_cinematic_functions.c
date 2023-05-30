/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** start_cinematic_functions.c
*/

#include "../../../include/my_rpg/my_rpg.h"
#include "../../../include/scenes/start_cinematic/struct.h"

void draw_start_cinematic(void *data, game_t *game)
{
    start_cinematic_object *start = CAST_START_CINEMATIC(data);

    sfRenderWindow_drawSprite(game->win->renderer, start->map_cache, NULL);
    sfRenderWindow_drawRectangleShape(game->win->renderer,
    start->fade_in, NULL);
    sfRenderWindow_setView(game->win->renderer,
    sfRenderWindow_getDefaultView(game->win->renderer));
    display_dialog(game->dialog, game->win);
}

void update_start_cinematic(void *data, game_t *game)
{
    start_cinematic_object *start = CAST_START_CINEMATIC(data);

    if (start->color.a >= (255 - 2) && start->display_fade_in) {
        start->display_fade_in = 0;
        start->display_dialog = 1;
        game->dialog->fd = fopen("./data/scenes/start_cinematic/text/st", "r");
        if (game->dialog->fd == NULL)
            write(2, "dialogbox: file not found\n", 26);
        game->dialog->run = 1;
    }
    if (start->display_dialog) {
        dialog_go_to_next_line(game->dialog, game->win,
        &start->delay_update_line);
        if (!game->dialog->run && start->wait_steps > start->wait_ms_delay) {
            start->display_dialog = 0;
            switch_scene(game, MAIN_MAP_NIGHT, "main_map_night");
        }
    }
}

void event_start_cinematic(void *data, game_t *game)
{

}

void destroy_start_cinematic(void *data, game_t *game)
{

}

void timer_start_cinematic(void *data, game_t *game)
{
    start_cinematic_object *start = CAST_START_CINEMATIC(data);

    if (start->color.a < (255 - 2) && start->display_fade_in) {
        start->color.a += 2;
        sfRectangleShape_setFillColor(start->fade_in, start->color);
    }
    if (start->display_dialog) {
        start->delay_update_char += 0.1;
        if (game->dialog->is_begin_of_dialog && game->dialog->mode == CINEMATIC
        && game->dialog->buffer[game->dialog->i] == '\0')
            start->delay_update_line += 0.1;
        if ((start->delay_update_char > ((double)game->dialog->ms_delay_current
        / (double)start->ms_delay)) ||
        game->dialog->buffer[game->dialog->i] == ' ') {
            start->delay_update_char = 0;
            update_dialog_text(game->dialog, NULL, game->win);
        }
        if (start->display_dialog && !game->dialog->run)
            start->wait_steps++;
    }
}
