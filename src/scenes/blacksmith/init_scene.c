/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

void init_blacksmith_three(game_t *game, shop_t *shop)
{
    sfVector2u win_size = sfRenderWindow_getSize(game->win->renderer);

    sfVector2f pos = sfRectangleShape_getPosition(game->dialog->gui);
    sfVector2f size = sfRectangleShape_getSize(game->dialog->gui);
    float thickness = sfRectangleShape_getOutlineThickness(game->dialog->gui);
    sfRectangleShape_move(game->dialog->gui,
    (sfVector2f){0, win_size.y - (size.y + pos.y + thickness)});
    sfText_move(game->dialog->text,
    (sfVector2f){0, win_size.y - (size.y + pos.y)});
    set_dialog_mode(game->dialog, DISCUSSION);
    set_triangle_visibility(game->dialog, 1);
    game->dialog->fd = fopen("./data/scenes/blacksmith/text/intro", "r");
    game->dialog->run = 1;
    add_to_object_list(game, init_object(shop, SHOP_OBJECT, "shop_object"),
    SHOP_OBJECT);
}

void init_blacksmith_two(game_t *game, shop_t *shop)
{
    set_shop_greeting_rect(shop, &(sfVector2f){shop->item_area_rect.left,
    shop->item_area_rect.top - 70}, game->dialog_font, game->textures_list);
    shop->quantity_money_str = my_int_to_str(((inventory_scene *)
    game->inventory_object->struct_type)->current_coins_nb);
    sfText_setString(shop->quantity_money, shop->quantity_money_str);
    sfMusic_setLoop(game->sounds->shop_music, sfTrue);
    sfMusic_play(game->sounds->shop_music);
}

void init_blacksmith_ext(game_t *game, shop_t *shop)
{
    sfVector2u win_size = sfRenderWindow_getSize(game->win->renderer);
    set_shop_items_rect(shop, &(sfIntRect){30,
    win_size.y - 270 - shop->outline_thickness - 30, 700, 270},
    game->dialog_font);
}

void init_blacksmith(game_t *game)
{
    static char *name_tags[] =
    {"fireblade", "shadowblade", "stormbreaker", "item.monster_candy"};
    static int quantity = 1;
    static char *price[] = {"150", "100", "120", "0"};
    static char *names[] =
    {"Fireblade", "Shadowblade", "Stormbreaker", "Exit"};
    static char *paths[] = {"./data/scenes/blacksmith/text/fireblade",
    "./data/scenes/blacksmith/text/shadowblade",
    "./data/scenes/blacksmith/text/stormbreaker",
    "./data/scenes/blacksmith/text/exit"};
    static item_type_inventory type = SWORD;
    shop_t *shop = create_shop(4, "selection_hand", game->textures_list);

    set_shop_appearance(shop, 5, sfBlack, sfWhite);
    for (int i = 0; i < shop->max_items_nb; i++)
        add_item_to_shop(shop, &(item_infos){name_tags[i], names[i],
        paths[i], quantity, price[i], type}, game->textures_list);
    init_blacksmith_ext(game, shop);
    init_blacksmith_two(game, shop);
    init_blacksmith_three(game, shop);
}
