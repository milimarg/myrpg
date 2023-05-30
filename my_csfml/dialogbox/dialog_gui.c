/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** dialog_gui.c
*/

#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include "dialogbox.h"

void init_dialog_gui(my_dialogbox *dialog, sfFloatRect *rect, my_window *window)
{
    sfVector2f value = {0};

    dialog->inner_offset = (sfVector2f){rect->left, rect->top};
    dialog->thickness = rect->width;
    dialog->gui = sfRectangleShape_create();
    value = (sfVector2f){window->width - (dialog->thickness * 2), rect->height};
    sfRectangleShape_setSize(dialog->gui, value);
    value = (sfVector2f){dialog->thickness, window->height - rect->height -
    dialog->thickness - dialog->inner_offset.y};
    sfRectangleShape_setPosition(dialog->gui, value);
    sfRectangleShape_setOutlineThickness(dialog->gui, dialog->thickness);
    dialog->text = sfText_create();
    value.x += dialog->inner_offset.x;
    value.y += 20;
    sfText_setPosition(dialog->text, value);
    sfText_setColor(dialog->text, sfWhite);
    sfText_setString(dialog->text, "");
}

void init_dialog_text(my_dialogbox *dialog, sfColor colors[4], sfFont *font,
unsigned int font_size)
{
    sfText_setFont(dialog->text, font);
    dialog->character_size = font_size;
    sfText_setCharacterSize(dialog->text, dialog->character_size);
    sfRectangleShape_setFillColor(dialog->gui, colors[0]);
    sfRectangleShape_setOutlineColor(dialog->gui, colors[1]);
    sfText_setColor(dialog->text, colors[2]);
    dialog->triangle_color = colors[3];
}
