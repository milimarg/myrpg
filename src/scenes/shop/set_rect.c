/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** set_rect
*/

#include "../../../include/my_rpg/my_rpg.h"
#include "../../../include/scenes/inventory/struct.h"

void set_items_for_shop_rect(shop_t *shop, sfFont *font)
{
    sfVector2f pos = {0};
    char *str = NULL;

    for (int i = 0; i < shop->max_items_nb; i++) {
        if (shop->items[i].empty)
            continue;
        pos.x = shop->item_area_rect.left + 70;
        pos.y = shop->item_area_rect.top + (i * 50) + 20;
        sfText_setPosition(shop->items[i].display_text, pos);
        sfText_setFont(shop->items[i].display_text, font);
        sfText_setString(shop->items[i].display_text,
        shop->items[i].infos.display_name);
        pos.x += (shop->item_area_rect.width - 70 - 50);
        sfSprite_setPosition(shop->items[i].money_sprite, pos);
        pos.x -= 60;
        sfText_setPosition(shop->items[i].quantity_text, pos);
        sfText_setFont(shop->items[i].quantity_text, font);
        sfText_setString(shop->items[i].quantity_text,
        shop->items[i].infos.price);
    }
}

void set_shop_items_rect(shop_t *shop, sfIntRect *rect, sfFont *font)
{
    shop->item_area = sfRectangleShape_create();
    shop->item_area_rect.left = rect->left + shop->outline_thickness;
    shop->item_area_rect.top = rect->top;
    shop->item_area_rect.width = rect->width;
    shop->item_area_rect.height = rect->height;
    sfRectangleShape_setPosition(shop->item_area,
    (sfVector2f){shop->item_area_rect.left, shop->item_area_rect.top});
    sfRectangleShape_setSize(shop->item_area,
    (sfVector2f){shop->item_area_rect.width, shop->item_area_rect.height});
    sfRectangleShape_setFillColor(shop->item_area, shop->bg_color);
    sfRectangleShape_setOutlineColor(shop->item_area, shop->outline_color);
    sfRectangleShape_setOutlineThickness(shop->item_area,
    shop->outline_thickness);
    set_items_for_shop_rect(shop, font);
}
