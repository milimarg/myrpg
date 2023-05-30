/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** entity_functions
*/

#include "../../../include/my_rpg/my_rpg.h"

void draw_entity(void *data, game_t *game)
{
    my_entity *entity = CAST_ENTITY(data);

    sfRenderWindow_drawSprite(game->win->renderer, entity->anim->sprite, NULL);
}

void update_entity(void *data, game_t *game)
{

}

void event_entity(void *data, sfEvent Event, game_t *game)
{

}

void destroy_entity(void *data, game_t *game)
{

}

void timer_entity(void *data, game_t *game)
{

}
