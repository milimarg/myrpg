/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** npc_functions
*/

#include "../../../include/my_rpg/my_rpg.h"

void draw_npc(void *data, game_t *game)
{
    npc_t *npc = CAST_NPC(data);

    sfRenderWindow_drawSprite(game->win->renderer,
    npc->entity->anim->sprite, NULL);
}

void update_npc(void *data, game_t *game)
{
    npc_t *npc = CAST_NPC(data);

    sfSprite_setPosition(npc->entity->anim->sprite, npc->entity->position);
}

void event_npc(void *data, sfEvent Event, game_t *game)
{

}

void destroy_npc(void *data, game_t *game)
{

}

void timer_npc(void *data, game_t *game)
{

}
