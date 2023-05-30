/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** up_functions_two
*/

#include "../../../include/my_rpg/my_rpg.h"

void update_player_hp_display(game_t *game)
{
    free(game->ui->hp_text->string);
    game->ui->hp_text->string = my_int_to_str(game->player->current_hp);
    sfText_setString(game->ui->hp_text->text, game->ui->hp_text->string);
}
