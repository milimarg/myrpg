/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** mob_functions
*/

#include "../../../include/my_rpg/my_rpg.h"

void draw_mob(void *data, game_t *game)
{
    mob_t *mob = CAST_MOB(data);

    sfRenderWindow_drawSprite(game->win->renderer,
    mob->entity_mob->anim->sprite, NULL);
}

void update_mob(void *data, game_t *game)
{
    mob_t *mob = CAST_MOB(data);

    move_mob_tavern(game, mob);
}

void event_mob(void *data, sfEvent Event, game_t *game)
{

}

void destroy_mob(void *data, game_t *game)
{

}

void timer_mob(void *data, game_t *game)
{

}
