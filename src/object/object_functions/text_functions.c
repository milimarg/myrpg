/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** text_functions
*/

#include "../../../include/my_rpg/my_rpg.h"

void draw_text(void *data, game_t *game)
{
    text_t *text = CAST_TEXT(data);

    if (my_strcmp(text->string, "E") == 0)
        if (!game->quests->display_text
        && !game->quests->display_text2
        && !game->quests->display_text3)
            return;
    sfRenderWindow_drawText(game->win->renderer, text->text, NULL);
}

void update_text(void *data, game_t *game)

{
    text_t *text = CAST_TEXT(data);
    sfVector2f pos = text->pos;

    pos.x /= game->win->ratio.x;
    pos.y /= game->win->ratio.y;
    sfText_setPosition(text->text, pos);
    sfText_setScale(text->text,
    (sfVector2f){1 / game->win->ratio.x, 1 / game->win->ratio.y});
}

void event_text(void *data, sfEvent Event, game_t *game)
{

}

void destroy_text(void *data, game_t *game)
{

}

void timer_text(void *data, game_t *game)
{

}
