/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** inventory_utils
*/

#include "../../../include/my_rpg/my_rpg.h"
#include "../../../include/scenes/inventory/prototype.h"

void swap_item(items_list *item_a, items_list *item_b)
{
    items_list temp = {0};

    temp = *item_a;
    *item_a = *item_b;
    *item_b = temp;
}

int check_slots_items_allowed(int i, inventory_scene *inventory)
{
    sfVector2f slot_pos = {0};

    if ((i == 0 && inventory->selected_item->infos.type != SWORD) ||
        (i == 1 && inventory->selected_item->infos.type != NECKLACE)) {
        slot_pos = sfRectangleShape_getPosition(inventory->slot_hitbox
        [inventory->selected_item_index]);
        sfSprite_setPosition(inventory->selected_item->sprite, slot_pos);
        return (1);
    }
    if (((inventory->selected_item_index == 0 && inventory->container->items
    [i]->infos.type != SWORD) || (inventory->selected_item_index == 1 &&
    inventory->container->items[i]->infos.type != NECKLACE)) && !inventory->
    container->items[i]->empty) {
        slot_pos = sfRectangleShape_getPosition(inventory->slot_hitbox
        [inventory->selected_item_index]);
        sfSprite_setPosition(inventory->selected_item->sprite, slot_pos);
        return (1);
    }
    return (0);
}

int check_click_on_item(int mouse_on_item, inventory_scene *inventory,
int i, sfVector2f *slot_pos)
{
    if (mouse_on_item && sfMouse_isButtonPressed(sfMouseLeft) &&
    !inventory->anti_spam_mouse && inventory->item_floating) {
        inventory->anti_spam_mouse = 1;
        inventory->selected_item->floating = 0;
        inventory->item_floating = 0;
        if (check_slots_items_allowed(i, inventory))
            return (1);
        *slot_pos = sfRectangleShape_getPosition(inventory->slot_hitbox[i]);
        sfSprite_setPosition(inventory->selected_item->sprite, *slot_pos);
        if (!inventory->container->items[i]->empty) {
            *slot_pos = sfRectangleShape_getPosition(
            inventory->slot_hitbox[inventory->selected_item_index]);
            sfSprite_setPosition(inventory->container->items[i]->sprite,
            *slot_pos);
        }
        swap_item(inventory->selected_item, inventory->container->items[i]);
    }
    return (0);
}

int detect_items_inventory(inventory_scene *inventory, int i,
sfVector2i *mouse)
{
    sfFloatRect slot_rect = {0};
    sfVector2f slot_pos = {0};
    int mouse_on_item = 0;

    slot_rect = sfRectangleShape_getGlobalBounds(inventory->slot_hitbox[i]);
    mouse_on_item = sfFloatRect_contains(&slot_rect, mouse->x, mouse->y);
    if (mouse_on_item && sfMouse_isButtonPressed(sfMouseLeft) &&
        !inventory->anti_spam_mouse && !inventory->item_floating &&
        inventory->container->items[i]->sprite != NULL) {
        inventory->anti_spam_mouse = 1;
        inventory->item_floating = 1;
        inventory->container->items[i]->floating = 1;
        inventory->selected_item_index = i;
        inventory->selected_item = inventory->container->items[i];
    }
    if (check_click_on_item(mouse_on_item, inventory, i, &slot_pos))
        return (1);
    if (!sfMouse_isButtonPressed(sfMouseLeft) && inventory->anti_spam_mouse)
        inventory->anti_spam_mouse = 0;
    return (0);
}
