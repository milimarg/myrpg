/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** display
*/

#include "../../../include/my_rpg/my_rpg.h"
#include "../../../include/scenes/inventory/struct.h"

static void condition_if(shop_t *shop, my_window *window, int i)
{
    if (i == shop->selected_item_index) {
        sfSprite_setPosition(shop->selection_element_sprite,
        (sfVector2f){shop->item_area_rect.left + 20,
        shop->item_area_rect.top + (i * 50) + 20});
    }
    if (!shop->items[i].empty) {
        sfRenderWindow_drawText(window->renderer,
        shop->items[i].display_text, NULL);
    }
    if (!shop->items[i].empty && my_getnbr(shop->items[i].infos.price)
    != 0) {
        sfRenderWindow_drawSprite(window->renderer,
        shop->items[i].money_sprite, NULL);
        sfRenderWindow_drawText(window->renderer,
        shop->items[i].quantity_text, NULL);
    }
}

void display_shop(shop_t *shop, my_window *window)
{
    sfRenderWindow_drawRectangleShape(window->renderer, shop->item_area, NULL);
    sfRenderWindow_drawRectangleShape(window->renderer,
    shop->greeting_message_area, NULL);
    for (int i = 0; i < shop->max_items_nb; i++)
        condition_if(shop, window, i);
    sfRenderWindow_drawText(window->renderer, shop->greeting_text, NULL);
    sfRenderWindow_drawSprite(window->renderer, shop->selection_element_sprite,
    NULL);
    sfRenderWindow_drawSprite(window->renderer, shop->money_sprite, NULL);
    sfRenderWindow_drawText(window->renderer, shop->quantity_money, NULL);
}
