/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** shop_give_item
*/

#include "../../../include/my_rpg/my_rpg.h"
#include "../../../include/scenes/inventory/struct.h"

static void give_item_from_shop_ext(shop_t *shop, my_dialogbox *dialog,
inventory_scene *inv, my_textures_list *list)
{
    shop->anti_spam_enter = 1;
    if (my_getnbr(shop->items[shop->selected_item_index].infos.price)
    <= inv->current_coins_nb) {
        dialog->fd =
        fopen(shop->items[shop->selected_item_index].infos.dialog_path,
        "r");
        dialog->run = 1;
        inv->current_coins_nb
        -= my_getnbr(shop->items[shop->selected_item_index].infos.price);
        add_item(inv->container,
        &shop->items[shop->selected_item_index].infos, list);
        set_item_position_shop(inv, shop);
        free(shop->quantity_money_str);
        shop->quantity_money_str = my_int_to_str(inv->current_coins_nb);
        sfText_setString(shop->quantity_money, shop->quantity_money_str);
    } else {
        dialog->fd = fopen("./data/scenes/shop/text/poor_people", "r");
        dialog->run = 1;
    }
}

void give_item_from_shop(shop_t *shop, my_dialogbox *dialog,
inventory_scene *inv, my_textures_list *list)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter) && !shop->anti_spam_enter &&
    my_strcmp(shop->items[shop->selected_item_index].infos.display_name,
    "Exit") != 0)
        give_item_from_shop_ext(shop, dialog, inv, list);
    if (sfKeyboard_isKeyPressed(sfKeyEnter) && !shop->anti_spam_enter &&
    my_strcmp(shop->items[shop->selected_item_index].infos.display_name,
    "Exit") == 0) {
        shop->anti_spam_enter = 1;
        dialog->fd =
        fopen(shop->items[shop->selected_item_index].infos.dialog_path, "r");
        dialog->run = 1;
    }
    if (!sfKeyboard_isKeyPressed(sfKeyEnter) && shop->anti_spam_enter)
        shop->anti_spam_enter = 0;
}
