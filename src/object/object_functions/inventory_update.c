/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** inventory_update
*/

#include "../../../include/my_rpg/my_rpg.h"
#include "../../../include/scenes/inventory/prototype.h"

void update_inventory(void *data, game_t *game)
{
    inventory_scene *inventory = CAST_INVENTORY(data);
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(game->win->renderer);
    sfVector2f float_pos = {0};

    for (int i = 0; i < inventory->container->max_items_nb; i++) {
        if (detect_items_inventory(inventory, i, &mouse_pos))
            return;
        if (inventory->container->items[i]->floating) {
            float_pos.x = mouse_pos.x -
            ((double)inventory->slot_texture_size.x / 2.0);
            float_pos.y = mouse_pos.y -
            ((double)inventory->slot_texture_size.y / 2.0);
            sfSprite_setPosition(inventory->container->items[i]->sprite,
            float_pos);
        }
    }
}
