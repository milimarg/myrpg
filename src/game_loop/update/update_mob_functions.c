/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** update_mob_functions
*/

#include "../../../include/my_rpg/my_rpg.h"

void check_bandit_chief_death(game_t *game, object_t *mob_obj)
{
    if (my_strcmp(mob_obj->id, "bandit_chief") == 0) {
        item_infos info = {"head", "head", "", 1, "",
        COMMON};
        add_item(((inventory_scene *)
        (game->inventory_object->struct_type))->container, &info,
        game->textures_list);
        set_item_position_inventory((inventory_scene *)
        (game->inventory_object->struct_type));
        sfText_setString(game->quests->text, game->quests->quests[6]);
        game->quests->index = 6;
    }
}

void remove_mob_from_list(game_t *game, linked_list_object_t *list)
{
    mob_t *mob = (mob_t *)list->object->struct_type;
    linked_list_object_t *temp = NULL;

    if (mob->current_hp_mob <= 0) {
        game->player->stats->global_xp += mob->xp;
        ((inventory_scene *)game->inventory_object->struct_type)
        ->current_coins_nb += mob->coin_mob;
        update_player_xp(game);
        check_bandit_chief_death(game, list->object);
        temp = game->current_scene->object_list;
        for (; temp->next != list && temp != NULL; temp = temp->next);
        if (temp == NULL) {
            game->current_scene->object_list = list->next;
            list->object->destroy(list->object->struct_type, game);
            return;
        }
        temp->next = list->next;
        list->object->destroy(list->object->struct_type, game);
    }
}
