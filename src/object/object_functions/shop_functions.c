/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** shop_functions.c
*/

#include "../../../include/my_rpg/my_rpg.h"
#include "../../../include/scenes/inventory/struct.h"

void draw_shop(void *data, game_t *game)
{
    shop_t *shop = CAST_SHOP(data);

}

void update_shop(void *data, game_t *game)
{
    shop_t *shop = CAST_SHOP(data);
    static double voila = 0;
    static int has_to_quit = 0;

    if (!game->dialog->run) {
        move_selection_shop(shop);
        give_item_from_shop(shop, game->dialog,
        (inventory_scene *)game->inventory_object->struct_type,
        game->textures_list);
    }
    if (game->dialog->run && sfKeyboard_isKeyPressed(sfKeyEnter) &&
    !my_strcmp(shop->items[shop->selected_item_index].infos.display_name,
    "Exit") && !has_to_quit)
        has_to_quit = 1;
    if (!game->dialog->run && has_to_quit) {
        has_to_quit = 0;
        sfMusic_stop(game->sounds->shop_music);
        switch_scene(game, MAIN_MAP, "main_map");
    }
    dialog_go_to_next_line(game->dialog, game->win, &voila);
}

void event_shop(void *data, sfEvent Event, game_t *game)
{

}

void destroy_shop(void *data, game_t *game)
{

}

void timer_shop(void *data, game_t *game)
{
    update_dialog_text(game->dialog, NULL, game->win);
}
/*
if (!game->dialog->run)
    display_shop(shop, game->win);
display_dialog(game->dialog, game->win);
*/
