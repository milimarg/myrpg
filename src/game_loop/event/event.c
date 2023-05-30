/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** event
*/

#include "../../../include/my_rpg/my_rpg.h"

void move_map_main_menu(game_t *game, int *move_map_steps);

void check_end(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void check_pause_trigger(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && !game->anti_spam_keyboard) {
        game->anti_spam_keyboard = 1;
        switch_scene(game, PAUSE, "pause");
    }
    if (!sfKeyboard_isKeyPressed(sfKeyEscape) && game->anti_spam_keyboard) {
        game->anti_spam_keyboard = 0;
    }
}

void event_loop(game_t *game, sfEvent event)
{
    while (sfRenderWindow_pollEvent(game->win->renderer, &event)) {
        check_end(game->win->renderer, event);
        for (linked_list_object_t *list = game->current_scene->object_list;
        list != NULL; list = list->next) {
            list->object->event(list->object->struct_type, event, game);
        }
    }
}

void event(game_t *game)
{
    static sfEvent event = {0};
    static sfInt64 current_time = 0;
    static sfInt64 clock_time = 0;
    static int move_map_steps = 0;

    clock_time = sfClock_getElapsedTime(game->win->clock).microseconds / 1000;
    if (clock_time - current_time > 5) {
        current_time = clock_time;
        move_map_steps++;
        game->player->move_steps++;
        game->player->sprite_steps++;
    }
    event_loop(game, event);
    if (game->current_scene->can_player_move == sfTrue) {
        check_pause_trigger(game);
    }
    if (game->current_scene->type == MAIN_MENU)
        move_map_main_menu(game, &move_map_steps);
}
