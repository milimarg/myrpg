/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** title
*/

#include "../../../../include/my_rpg/my_rpg.h"

void button_title(void *data)
{

}

void back_to_main_menu(void *data)
{
    game_t *game = data;

    switch_scene(game, MAIN_MENU, "main_menu");
}
