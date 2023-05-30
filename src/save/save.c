/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** save
*/

#include "../../include/my_rpg/my_rpg.h"

void save_inventory_two(game_t *game, save_t *save)
{
    save->inventory_items.slot14 = NOTHING;
    save->inventory_items.slot15 = NOTHING;
    save->inventory_items.slot16 = NOTHING;
    save->inventory_items.slot17 = NOTHING;
    save->inventory_items.slot18 = NOTHING;
    save->inventory_items.slot19 = NOTHING;
    save->inventory_items.slot20 = NOTHING;
    save->inventory_items.slot21 = NOTHING;
    save->inventory_items.slot22 = NOTHING;
    save->inventory_items.slot23 = NOTHING;
    save->inventory_items.slot24 = NOTHING;
    save->inventory_items.sword_slot = TEST;
    save->inventory_items.amulet_slot = TEST;
}

void save_inventory(game_t *game, save_t *save)
{
    save->inventory_items.slot1 = NOTHING;
    save->inventory_items.slot1 = NOTHING;
    save->inventory_items.slot2 = NOTHING;
    save->inventory_items.slot3 = NOTHING;
    save->inventory_items.slot4 = NOTHING;
    save->inventory_items.slot5 = NOTHING;
    save->inventory_items.slot6 = NOTHING;
    save->inventory_items.slot7 = NOTHING;
    save->inventory_items.slot8 = NOTHING;
    save->inventory_items.slot9 = NOTHING;
    save->inventory_items.slot10 = NOTHING;
    save->inventory_items.slot11 = NOTHING;
    save->inventory_items.slot12 = NOTHING;
    save->inventory_items.slot13 = NOTHING;
    save_inventory_two(game, save);
}

static void save_stats(game_t *game, save_t *save)
{
    save->stats.dexterity = game->player->stats->dexterity;
    save->stats.global_xp = game->player->stats->global_xp;
    save->stats.hp = game->player->stats->hp;
    save->stats.level = game->player->stats->level;
    save->stats.resistance = game->player->stats->resistance;
    save->stats.resistance_xp = game->player->stats->resistance_xp;
    save->stats.strength = game->player->stats->strength;
    save->stats.strength_xp = game->player->stats->strength_xp;
}

void save(game_t *game)
{
    save_t save = {0};
    int fd = open("./save/save.rpgs", O_WRONLY | O_TRUNC | O_CREAT, 0644);
    pause_object *pause = NULL;

    if (game->current_scene->type == PAUSE) {
        pause = find_in_object_list(game, "pause_object")->struct_type;
        save.scene = pause->previous_scene;
    } else {
        save.scene = game->current_scene->type;
    }
    save.pos_player = sfView_getCenter(game->win->view);
    save.quest_index = game->quests->index;
    save_stats(game, &save);
    save_inventory(game, &save);
    write(fd, &save, sizeof(save_t));
    game->already_saved = sfTrue;
    close(fd);
}
