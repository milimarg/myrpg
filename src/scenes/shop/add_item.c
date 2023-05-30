/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** add_item
*/

#include "../../../include/my_rpg/my_rpg.h"
#include "../../../include/scenes/inventory/struct.h"

void add_item_to_shop_ext(shop_t *shop, item_infos *item_info,
my_textures_list *list, my_textures_list *to_match)
{
    shop->items[shop->i].empty = 0;
    shop->items[shop->i].infos = *item_info;
    sfSprite_setTexture(shop->items[shop->i].sprite, to_match->texture,
    sfTrue);
    shop->items[shop->i].money_sprite = sfSprite_create();
    sfSprite_setTexture(shop->items[shop->i].money_sprite,
    find_texture_in_list(list, "money_shop")->texture, sfTrue);
    sfSprite_setScale(shop->items[shop->i].money_sprite,
    (sfVector2f){0.25, 0.25});
    shop->items[shop->i].quantity_text = sfText_create();
    shop->i++;
}

void add_item_to_shop(shop_t *shop, item_infos *item_info,
my_textures_list *list)
{
    my_textures_list *to_match =
    find_texture_in_list(list, item_info->name_tag);

    if (shop->i == shop->max_items_nb) {
        write(2, "shop error: cannot add item, inventory full\n", 44);
        return;
    }
    if (to_match == NULL) {
        write(2, "shop error: could not find texture\n", 35);
        return;
    }
    add_item_to_shop_ext(shop, item_info, list, to_match);
}
