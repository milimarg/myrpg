/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** take_flower
*/

#include "../../../include/my_rpg/my_rpg.h"

void remove_flowers(game_t *game)
{
    int index = 0;

    for (int i = 0; i < 3; i++) {
        index = find_item_in_container(((inventory_scene *)
        (game->inventory_object->struct_type))->container, "moonbloom");
        remove_item(((inventory_scene *)
        (game->inventory_object->struct_type))->container, index);
        sfText_setString(game->quests->text, game->quests->quests[8]);
        game->quests->index = 8;
    }
}

void take_flower_3(game_t *game, sfVector2f pos_player)
{
    npc_t *f3 =
    (npc_t *)(find_in_object_list(game, "moonbloom3")->struct_type);
    sfVector2f pos_3 = sfSprite_getPosition(f3->entity->anim->sprite);
    static int taken = 0;
    if (pos_player.x - pos_3.x < 30 && pos_player.x - pos_3.x > - 30
    && pos_player.y - pos_3.y < 30 && pos_player.y - pos_3.y > -30 && !taken) {
        game->quests->display_text3 = sfTrue;
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            item_infos info = {"moonbloom", "Moonbloom", "", 1, "",
            COMMON};
            add_item(((inventory_scene *)
            (game->inventory_object->struct_type))->container, &info,
            game->textures_list);
            set_item_position_inventory((inventory_scene *)
            (game->inventory_object->struct_type));
            game->quests->counter++;
            taken = 1;
        }
    } else
        game->quests->display_text3 = sfFalse;
}

void take_flower_2(game_t *game, sfVector2f pos_player)
{
    npc_t *f2 =
    (npc_t *)(find_in_object_list(game, "moonbloom2")->struct_type);
    sfVector2f pos_2 = sfSprite_getPosition(f2->entity->anim->sprite);
    static int taken = 0;
    if (pos_player.x - pos_2.x < 30 && pos_player.x - pos_2.x > - 30
    && pos_player.y - pos_2.y < 30 && pos_player.y - pos_2.y > -30 && !taken) {
        game->quests->display_text2 = sfTrue;
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            item_infos info = {"moonbloom", "Moonbloom", "", 1, "", COMMON};
            add_item(((inventory_scene *)
            (game->inventory_object->struct_type))->container, &info,
            game->textures_list);
            set_item_position_inventory((inventory_scene *)
            (game->inventory_object->struct_type));
            game->quests->counter++;
            taken = 1;
        }
    } else
        game->quests->display_text2 = sfFalse;
    take_flower_3(game, pos_player);
}

void take_flower(game_t *game)
{
    npc_t *f = (npc_t *)(find_in_object_list(game, "moonbloom1")->struct_type);
    sfVector2f posp = sfSprite_getPosition(game->player->entity->anim->sprite);
    sfVector2f pos_1 = sfSprite_getPosition(f->entity->anim->sprite);
    static int taken = 0;
    if (posp.x - pos_1.x < 30 && posp.x - pos_1.x > - 30
    && posp.y - pos_1.y < 30 && posp.y - pos_1.y > -30 && !taken) {
        game->quests->display_text = sfTrue;
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            item_infos info = {"moonbloom", "Moonbloom", "", 1, "", COMMON};
            add_item(((inventory_scene *)
            (game->inventory_object->struct_type))->container, &info,
            game->textures_list);
            set_item_position_inventory((inventory_scene *)
            (game->inventory_object->struct_type));
            game->quests->counter++;
            taken = 1;
        }
    } else
        game->quests->display_text = sfFalse;
    take_flower_2(game, posp);
}
