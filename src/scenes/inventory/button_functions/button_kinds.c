/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** button_kinds
*/

#include "../../../../include/my_rpg/my_rpg.h"

void hp_up(void *data)
{
    game_t *game = data;
    text_t *text = NULL;

    if (game->player->stats->stat_point < 0)
        return;
    game->player->stats->stat_point--;
    game->player->stats->hp++;
    text = (text_t *)(find_in_object_list(game, "hp_text")->struct_type);
    free(text->string);
    text->string = my_int_to_str(game->player->stats->hp);
    sfText_setString(text->text, text->string);
    update_player_hp_display(game);
}

void res_up(void *data)
{
    game_t *game = data;
    text_t *text = NULL;

    if (game->player->stats->stat_point < 0)
        return;
    game->player->stats->stat_point--;
    game->player->stats->resistance++;
    text = (text_t *)(find_in_object_list(game, "res_text")->struct_type);
    free(text->string);
    text->string = my_int_to_str(game->player->stats->resistance);
    sfText_setString(text->text, text->string);
}

void atk_up(void *data)
{
    game_t *game = data;
    text_t *text = NULL;

    if (game->player->stats->stat_point < 0)
        return;
    game->player->stats->stat_point--;
    game->player->stats->strength++;
    text = (text_t *)(find_in_object_list(game, "attack_text")->struct_type);
    free(text->string);
    text->string = my_int_to_str(game->player->stats->strength);
    sfText_setString(text->text, text->string);
}

void speed_up(void *data)
{
    game_t *game = (game_t *)data;
    text_t *text = NULL;

    if (game->player->stats->stat_point < 0)
        return;
    game->player->stats->stat_point--;
    game->player->stats->dexterity++;
    text = (text_t *)(find_in_object_list(game, "speed_text")->struct_type);
    free(text->string);
    text->string = my_int_to_str(game->player->stats->dexterity);
    sfText_setString(text->text, text->string);
}
