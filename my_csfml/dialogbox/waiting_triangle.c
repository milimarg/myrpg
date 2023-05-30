/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** waiting_triangle.c
*/

#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include "dialogbox.h"

void update_triangle(my_dialogbox *dialog)
{
    static int fade = 0;
    int offset = 5;
    int size = 15;
    sfVector2f pos = dialog->triangle_pos;
    sfVertex vertex = {pos, dialog->triangle_color, {0}};

    fade = (dialog->triangle_color.a <= offset && !fade) ? 1 : fade;
    fade = (dialog->triangle_color.a >= (254 - offset) && fade) ? 0 : fade;
    dialog->triangle_color.a = (fade) ? dialog->triangle_color.a + offset :
    dialog->triangle_color.a - offset;
    sfVertexArray_clear(dialog->wait_triangle);
    sfVertexArray_append(dialog->wait_triangle, vertex);
    vertex.color = dialog->triangle_color;
    vertex.position = (sfVector2f){pos.x + size, pos.y};
    sfVertexArray_append(dialog->wait_triangle, vertex);
    vertex.color = dialog->triangle_color;
    vertex.position = (sfVector2f){pos.x + (size / 2), pos.y + (size / 2)};
    sfVertexArray_append(dialog->wait_triangle, vertex);
    sfVertexArray_setPrimitiveType(dialog->wait_triangle, sfTriangles);
}

void update_triangle_pos(my_dialogbox *dialog)
{
    sfVector2f last_char_pos = {0};

    dialog->display_triangle = 1;
    last_char_pos = sfText_findCharacterPos(dialog->text,
    dialog->text_idx - 1);
    last_char_pos.x += 10;
    last_char_pos.y += (double)dialog->character_size / 2.0;
    dialog->triangle_pos = last_char_pos;
}

void set_triangle_visibility(my_dialogbox *dialog, int is_visible)
{
    is_visible = (is_visible < 0) ? 0 : is_visible;
    is_visible = (is_visible > 1) ? 1 : is_visible;
    dialog->triangle_visibility = is_visible;
}
