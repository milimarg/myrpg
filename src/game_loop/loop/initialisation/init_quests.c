/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_quests
*/

#include "../../../../include/my_rpg/my_rpg.h"

void init_quests_strings(game_t *game)
{
    int nb_quests = 10;

    game->quests->quests = malloc(sizeof(char *) * (nb_quests + 1));
    game->quests->quests[0] = "Find and enter the castle";
    game->quests->quests[1] = "Knock out the guard";
    game->quests->quests[2] = "Enter the castle and find the sacred\n jewel";
    game->quests->quests[3] = "Exit without being caught";
    game->quests->quests[4] = "";
    game->quests->quests[5] = "Find and kill the Pillagers";
    game->quests->quests[6] = "Go see the wizard";
    game->quests->quests[7] = "Collect the plants for the wizard";
    game->quests->quests[8] = "Retrieve the relic from Dante's Maze";
    game->quests->quests[9] = "Bring the items to King Marvin";
}

void init_quests(game_t *game)
{
    game->quests = malloc(sizeof(quests_t));
    game->quests->text = sfText_create();
    init_quests_strings(game);

    game->quests->counter = 0;
    game->quests->display_text = sfFalse;
    game->quests->display_text2 = sfFalse;
    game->quests->display_text3 = sfFalse;
    sfText_setFont(game->quests->text, game->main_font);
    sfText_setCharacterSize(game->quests->text, 25);
    sfText_setColor(game->quests->text, sfBlack);
    sfText_setPosition(game->quests->text, (sfVector2f){80, 120});
    sfText_setString(game->quests->text, game->quests->quests[0]);
    game->quests->index = 0;
}
