/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** move_item
*/

#include "../../../include/my_rpg/my_rpg.h"
#include "../../../include/scenes/inventory/struct.h"

void move_selection_shop(shop_t *shop)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) && !shop->anti_spam_mouse1 &&
    shop->selected_item_index > 0) {
        shop->anti_spam_mouse1 = 1;
        shop->selected_item_index--;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && !shop->anti_spam_mouse2 &&
    shop->selected_item_index < shop->max_items_nb - 1) {
        shop->anti_spam_mouse2 = 1;
        shop->selected_item_index++;
    }
    if (!sfKeyboard_isKeyPressed(sfKeyUp) && shop->anti_spam_mouse1)
        shop->anti_spam_mouse1 = 0;
    if (!sfKeyboard_isKeyPressed(sfKeyDown) && shop->anti_spam_mouse2)
        shop->anti_spam_mouse2 = 0;
}

void set_item_position_inventory(inventory_scene *inv)
{
    sfVector2f slot_pos = {0};

    slot_pos =
    sfRectangleShape_getPosition(inv->slot_hitbox[inv->container->last_index]);
    sfSprite_setPosition(inv->container->items
    [inv->container->last_index]->sprite, slot_pos);
}

void set_item_position_shop(inventory_scene *inv, shop_t *shop)
{
    sfVector2f slot_pos = {0};

    for (int j = 0; j < inv->container->max_items_nb; j++) {
        if (!inv->container->items[j]->empty && !my_strcmp(inv->
        container->items[j]->infos.display_name,
        shop->items[shop->selected_item_index].infos.display_name)) {
            slot_pos = sfRectangleShape_getPosition(inv->slot_hitbox[j]);
            sfSprite_setPosition(inv->container->items[j]->sprite,slot_pos);
        }
    }
}
