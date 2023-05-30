/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** greeting
*/

#include "../../../include/my_rpg/my_rpg.h"
#include "../../../include/scenes/inventory/struct.h"

static void greeting_rect_one(shop_t *shop, sfVector2f *pos, sfFont *font,
my_textures_list *list)
{
    shop->greeting_message_area = sfRectangleShape_create();
    shop->greeting_rect.width = shop->item_area_rect.width;
    shop->greeting_rect.height = 70;
    shop->greeting_rect.left = pos->x;
    shop->greeting_rect.top = pos->y;
    sfRectangleShape_setPosition(shop->greeting_message_area,
    (sfVector2f){shop->greeting_rect.left, shop->greeting_rect.top});
    sfRectangleShape_setSize(shop->greeting_message_area,
    (sfVector2f){shop->greeting_rect.width, shop->greeting_rect.height});
    sfRectangleShape_setFillColor(shop->greeting_message_area, shop->bg_color);
    sfRectangleShape_setOutlineColor(shop->greeting_message_area,
    shop->outline_color);
    sfRectangleShape_setOutlineThickness(shop->greeting_message_area,
    shop->outline_thickness);
    shop->greeting_text = sfText_create();
    sfText_setPosition(shop->greeting_text,
    (sfVector2f){shop->greeting_rect.left + 15, shop->greeting_rect.top + 15});
    sfText_setFont(shop->greeting_text, font);
    sfText_setString(shop->greeting_text, "What would you like to buy?");
}

void set_shop_greeting_rect(shop_t *shop, sfVector2f *pos, sfFont *font,
my_textures_list *list)
{
    sfVector2f my_money_pos = {0};

    greeting_rect_one(shop, pos, font, list);
    my_money_pos.x = shop->item_area_rect.left
    + shop->item_area_rect.width - 50;
    my_money_pos.y = shop->item_area_rect.top - 50;
    shop->money_sprite = sfSprite_create();
    sfSprite_setTexture(shop->money_sprite,
    find_texture_in_list(list, "money_shop")->texture, sfTrue);
    sfSprite_setPosition(shop->money_sprite, my_money_pos);
    sfSprite_setScale(shop->money_sprite, (sfVector2f){0.25, 0.25});
    my_money_pos.x -= 60;
    shop->quantity_money = sfText_create();
    sfText_setPosition(shop->quantity_money, my_money_pos);
    sfText_setFont(shop->quantity_money, font);
}
