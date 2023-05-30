/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** inventory_functions.c
*/

#include "../../../include/my_rpg/my_rpg.h"
#include "../../../include/scenes/inventory/prototype.h"

void draw_inventory(void *data, game_t *game)
{
    inventory_scene *inventory = CAST_INVENTORY(data);

    sfRenderWindow_setView(game->win->renderer,
    sfRenderWindow_getDefaultView(game->win->renderer));
    sfRenderWindow_drawRectangleShape(game->win->renderer, inventory->filter,
    NULL);
    sfRenderWindow_drawSprite(game->win->renderer, inventory->sprite, NULL);
    for (int i = 0; i < inventory->container->max_items_nb; i++) {
        if (!inventory->container->items[i]->empty) {
            sfRenderWindow_drawSprite(game->win->renderer,
            inventory->container->items[i]->sprite, NULL);
        }
    }
}

void event_inventory(void *data, sfEvent Event, game_t *game)
{
    inventory_scene *inventory = CAST_INVENTORY(data);


}

void destroy_inventory(void *data, game_t *game)
{
    inventory_scene *inventory = CAST_INVENTORY(data);


}

void timer_inventory(void *data, game_t *game)
{

}
