/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

static void init_one(shop_t *shop, int quantity, game_t *game)
{
    sfVector2u win_size = sfRenderWindow_getSize(game->win->renderer);
    set_shop_items_rect(shop, &(sfIntRect){30,
    win_size.y - 270 - shop->outline_thickness - 30, 700, 270},
    game->dialog_font);
    set_shop_greeting_rect(shop, &(sfVector2f){shop->item_area_rect.left,
    shop->item_area_rect.top - 70}, game->dialog_font, game->textures_list);
    shop->quantity_money_str = my_int_to_str(((inventory_scene *)
    game->inventory_object->struct_type)->current_coins_nb);
    sfText_setString(shop->quantity_money, shop->quantity_money_str);
    sfMusic_setLoop(game->sounds->shop_music, sfTrue);
    sfMusic_play(game->sounds->shop_music);
    sfVector2f pos = sfRectangleShape_getPosition(game->dialog->gui);
    sfVector2f size = sfRectangleShape_getSize(game->dialog->gui);
    float thickness = sfRectangleShape_getOutlineThickness(game->dialog->gui);
    sfRectangleShape_move(game->dialog->gui,
    (sfVector2f){0, win_size.y - (size.y + pos.y + thickness)});
    sfText_move(game->dialog->text,
    (sfVector2f){0, win_size.y - (size.y + pos.y)});
}

static void init_two(game_t *game, shop_t *shop)
{
    set_dialog_mode(game->dialog, DISCUSSION);
    set_triangle_visibility(game->dialog, 1);
    game->dialog->fd = fopen("./data/scenes/shop/text/welcome", "r");
    game->dialog->run = 1;
    add_to_object_list(game, init_object(shop, SHOP_OBJECT, "shop_object"),
    SHOP_OBJECT);
}

void init_shop(game_t *game)
{
    static char *name_tags[] =
    {"red_gem", "blue_gem", "yellow_gem", "purple_gem", "item.monster_candy"};
    static int quantity = 1;
    static char *price[] = {"60", "40", "30", "50", "0"};
    static char *names[] =
    {"Health Amulet", "Resistance Amulet", "Speed Amulet", "Strengh Amulet",
    "Exit"};
    static char *paths[] = {"./data/scenes/shop/text/health_amulet",
    "./data/scenes/shop/text/resistance_amulet",
    "./data/scenes/shop/text/speed_amulet",
    "./data/scenes/shop/text/strength_amulet", "./data/scenes/shop/text/exit"};
    static item_type_inventory type = NECKLACE;
    shop_t *shop = create_shop(5, "selection_hand", game->textures_list);

    set_shop_appearance(shop, 5, sfBlack, sfWhite);
    for (int i = 0; i < shop->max_items_nb; i++)
        add_item_to_shop(shop, &(item_infos){name_tags[i], names[i],
        paths[i], quantity, price[i], type}, game->textures_list);
    init_one(shop, quantity, game);
    init_two(game, shop);
}
