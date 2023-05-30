/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** pause_functions.c
*/

#include "../../../include/my_rpg/my_rpg.h"

void draw_pause(void *data, game_t *game)
{
    pause_object *pause = CAST_PAUSE(data);

    sfRenderWindow_setView(game->win->renderer,
    sfRenderWindow_getDefaultView(game->win->renderer));
    sfRenderWindow_drawRectangleShape(game->win->renderer, pause->filter, NULL);
}

void update_pause(void *data, game_t *game)
{

}

void event_pause(void *data, sfEvent event, game_t *game)
{
    pause_object *pause = CAST_PAUSE(data);

    if (!game->anti_spam_keyboard && sfKeyboard_isKeyPressed(sfKeyEscape)
    && (game->current_scene->can_player_move
    || game->current_scene->type == PAUSE)) {
        game->anti_spam_keyboard = 1;
        switch_scene(game, pause->previous_scene,
        SCENE_TYPE_ID[pause->previous_scene]);
    }
    if (game->anti_spam_keyboard && !sfKeyboard_isKeyPressed(sfKeyEscape))
        game->anti_spam_keyboard = 0;
}

void destroy_pause(void *data, game_t *game)
{

}

void timer_pause(void *data, game_t *game)
{

}
