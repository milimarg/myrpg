/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** image_functions
*/

#include "../../../include/my_rpg/my_rpg.h"

void draw_image(void *data, game_t *game)
{
    image_t *image = CAST_IMAGE(data);

    sfRenderWindow_drawSprite(game->win->renderer, image->sprite, NULL);
}

void update_image(void *data, game_t *game)
{
    image_t *image = CAST_IMAGE(data);
    sfVector2f pos = image->pos;

    pos.x /= game->win->ratio.x;
    pos.y /= game->win->ratio.y;
    sfSprite_setPosition(image->sprite, pos);
    sfSprite_setScale(image->sprite,
    (sfVector2f){1 / game->win->ratio.x, 1 / game->win->ratio.y});
}

void event_image(void *data, sfEvent Event, game_t *game)
{

}

void destroy_image(void *data, game_t *game)
{

}

void timer_image(void *data, game_t *game)
{

}
