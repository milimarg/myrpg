/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_player
*/

#include "../../../../include/my_rpg/my_rpg.h"

stats_t *init_player_stats(void)
{
    stats_t *stats = malloc(sizeof(stats_t));

    stats->resistance = BASE_RESISTANCE;
    stats->hp = BASE_HP;
    stats->strength = BASE_STRENGTH;
    stats->dexterity = BASE_DEXTERITY;
    stats->level = 1;
    stats->global_xp = 0;
    stats->resistance_xp = 0;
    stats->strength_xp = 0;
    stats->stat_point = 0;
    return (stats);
}

void init_player_values(game_t *game, player_t *player)
{
    player->stats = init_player_stats();
    player->speed = player->stats->dexterity / 10.0;
    player->move_steps = 0;
    player->move_steps_max = 1;
    player->sprite_steps = 0;
    player->sprite_steps_max = 20;
    player->current_hp = player->stats->hp;
    player->is_captured = sfFalse;
    player->is_attacked = sfFalse;
    player->can_i_move = 0;
    player->current_key = -1;
    player->last_key = -1;
}

void init_player_regen_timer(player_t *player)
{
    player->regen_timer = malloc(sizeof(timer_regeneration_t));
    player->regen_timer->interval = 0.0;
    player->regen_timer->elapsed_time = 0.0;
    player->regen_timer->defined_limit = 15.0;
    player->regen_timer->hp_interval = 0.0;
    player->regen_timer->hp_elapsed_time = 0.0;
    player->regen_timer->hp_defined_limit = 1.0;
    player->regen_timer->switch_timer = 0;
}

player_t *init_player(game_t *game)
{
    player_t *player = malloc(sizeof(player_t));
    char *anims[] = {"player.up", "player.down", "player.left",
    "player.right"};
    char *paths[] = {"./assets/images/player/back/back_walking.png",
    "./assets/images/player/front/running_front.png",
    "./assets/images/player/left/running_left.png",
    "./assets/images/player/right/running.png"};
    my_texture_rect rects[] = {{0, 0, 1404, 456, 3}, {0, 0, 936, 456, 2},
    {0, 0, 3456, 456, 8}, {0, 0, 3456, 456, 8}};

    player->name = malloc(sizeof(char) * (50));
    player->stats = malloc(sizeof(stats_t));
    for (int i = 0; i < 4; i++)
        add_texture(&game->textures_list, anims[i], paths[i], &rects[i]);
    player->entity = spawn_entity(game->textures_list, "player.down", 3);
    sfSprite_setOrigin(player->entity->anim->sprite, (sfVector2f){234, 228});
    sfSprite_setScale(player->entity->anim->sprite, (sfVector2f){0.09, 0.09});
    init_player_values(game, player);
    init_player_regen_timer(player);
    return (player);
}
