/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** parsing_text
*/

#include "../../include/my_rpg/my_rpg.h"

const static sfColor COLOR_TAB[] = {
    (sfColor){255, 255, 255, 225},
    (sfColor){0, 0, 0, 225},
    (sfColor){234, 245, 10, 225},
    (sfColor){10, 67, 245, 225}
};

void parsing_text_next(text_t *text, game_t *game, char **tab_arg)
{
    sfText_setPosition(text->text, text->pos);
    sfText_setString(text->text, text->string);
    sfText_setColor(text->text, COLOR_TAB[my_getnbr(tab_arg[5])]);
    sfText_setCharacterSize(text->text, my_getnbr(tab_arg[6]));
    sfText_setFont(text->text, game->main_font);
}

int parsing_text(game_t *game, char **tab_arg, char *filepath)
{
    int len = 0;
    text_t *text = NULL;

    for (; tab_arg[len] != NULL; len++);
    if (len != 7) {
        write(2, filepath, my_strlen(filepath));
        write(2, ": wrong file\n", 13);
        return (84);
    }
    text = malloc(sizeof(text_t));
    text->id = tab_arg[1];
    text->text = sfText_create();
    text->string = tab_arg[2];
    text->pos.x = my_getnbr(tab_arg[3]);
    text->pos.y = my_getnbr(tab_arg[4]);
    parsing_text_next(text, game, tab_arg);
    add_to_object_list(game, init_object(text, TEXT, tab_arg[1]), TEXT);
    return (0);
}
