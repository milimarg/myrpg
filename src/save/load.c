/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** load
*/

#include "../../include/my_rpg/my_rpg.h"

void load_stats(game_t *game, save_t *save_filled)
{
    game->player->stats->dexterity = save_filled->stats.dexterity;
    game->player->stats->global_xp = save_filled->stats.global_xp;
    game->player->stats->hp = save_filled->stats.hp;
    game->player->stats->level = save_filled->stats.level;
    game->player->stats->resistance = save_filled->stats.resistance;
    game->player->stats->resistance_xp = save_filled->stats.resistance_xp;
    game->player->stats->strength = save_filled->stats.strength;
    game->player->stats->strength_xp = save_filled->stats.strength_xp;
}

void load_inventory(game_t *game, save_t *save_filled)
{

}

void load_save(game_t *game)
{
    save_t save_filled = {0};
    int fd = open("./save/save.rpgs", O_RDONLY);

    read(fd, &save_filled, sizeof(save_t));
    close(fd);
    switch_scene(game, save_filled.scene, SCENE_TYPE_ID[save_filled.scene]);
    sfView_setCenter(game->win->view, save_filled.pos_player);
    load_stats(game, &save_filled);
    load_inventory(game, &save_filled);
    game->quests->index = save_filled.quest_index;
    sfText_setString(game->quests->text,
    game->quests->quests[game->quests->index]);
}
