/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** parsing_button
*/

#include "../../include/my_rpg/my_rpg.h"

static void parsing_button_one(my_button *button, char **tab_arg, game_t *game,
char **name_tag_and_name)
{
    button->base_color = sfSprite_getColor(button->sprite);
    button->click_color = (sfColor){button->base_color.r + 100,
    button->base_color.g + 100, button->base_color.b + 100,
    button->base_color.a};
    button->hover_color = (sfColor){button->base_color.r + 150,
    button->base_color.g + 150, button->base_color.b + 150,
    button->base_color.a};
}

int parsing_button(game_t *game, char **tab_arg, char *filepath)
{
    int len = 0;
    char **name_tag_and_name = malloc(sizeof(char *) * (2));
    my_button *button = NULL;

    for (; tab_arg[len] != NULL; len++);
    if (len != 8) {
        write(2, filepath, my_strlen(filepath));
        write(2, ": wrong file\n", 13);
        return (84);
    }
    name_tag_and_name[0] = tab_arg[6];
    name_tag_and_name[1] = tab_arg[1];
    button = add_button(&(sfIntRect){my_getnbr(tab_arg[2]),
    my_getnbr(tab_arg[3]), my_getnbr(tab_arg[4]), my_getnbr(tab_arg[5])},
    name_tag_and_name, POINTER_TAB[my_getnbr(tab_arg[7])],
    game->textures_list);
    parsing_button_one(button, tab_arg, game, name_tag_and_name);
    add_to_object_list(game, init_object(button, BUTTON, tab_arg[1]), BUTTON);
    return (0);
}
