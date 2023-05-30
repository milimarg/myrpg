/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** draw_two
*/

#include "../../../include/my_rpg/my_rpg.h"

void draw_five_ext(game_t *game, linked_list_object_t *list)
{
    shop_t *shop = NULL;

    if (list->object->type == SHOP_OBJECT) {
        shop = (shop_t *)list->object->struct_type;
        if (!game->dialog->run)
            display_shop(shop, game->win);
        display_dialog(game->dialog, game->win);
    }
}

void draw_five(game_t *game)
{
    if (game->current_scene->type == SHOP ||
    game->current_scene->type == BLACKSMITH) {
        for (linked_list_object_t *list = game->current_scene->object_list;
            list != NULL; list = list->next) {
                draw_five_ext(game, list);
            }
    }
}
