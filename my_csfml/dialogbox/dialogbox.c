/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** read_file.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "dialogbox.h"

static void set_dialog_infos(my_dialogbox *dialog, int ms_delay_wait)
{
    dialog->skip_delay = 0;
    dialog->text_content = NULL;
    dialog->text_idx = 0;
    dialog->wait_triangle = sfVertexArray_create();
    dialog->display_triangle = 0;
    dialog->triangle_pos = (sfVector2f){0};
    dialog->mode = DISCUSSION;
    dialog->ms_wait_delay = ms_delay_wait;
    dialog->is_begin_of_dialog = 0;
    dialog->triangle_visibility = 1;
}

my_dialogbox *init_dialog(sfKeyCode key, int ms_delay_char,
int ms_delay_punc_char, int ms_delay_wait)
{
    my_dialogbox *dialog = malloc(sizeof(my_dialogbox));

    dialog->key = key;
    dialog->run = 0;
    dialog->clicked = 0;
    dialog->ms_delay = ms_delay_char;
    dialog->ms_delay_punc = ms_delay_punc_char;
    dialog->ms_delay_current = dialog->ms_delay;
    dialog->i = 0;
    dialog->reading = 0;
    dialog->punc_array = ",.!?";
    dialog->timer = 0;
    dialog->getline_bytes = 0;
    dialog->fd = NULL;
    set_dialog_infos(dialog, ms_delay_wait);
    return (dialog);
}

void close_dialog(my_dialogbox *dialog)
{
    if (dialog->fd != NULL) {
        fclose(dialog->fd);
        dialog->fd = NULL;
    }
    dialog->run = 0;
    dialog->clicked = 0;
    dialog->is_begin_of_dialog = 0;
}

void update_dialog_text(my_dialogbox *dialog, sfSound *sound, my_window *window)
{
    int check_punctuation = 0;

    if (dialog->reading && dialog->buffer[dialog->i] != '\0') {
        if (dialog->display_triangle) {
            dialog->display_triangle = 0;
            sfVertexArray_clear(dialog->wait_triangle);
            sfRenderWindow_drawVertexArray(window->renderer,
            dialog->wait_triangle, NULL);
        }
        check_punctuation = check_if_char_is_punctuation(dialog);
        if (!check_punctuation && dialog->ms_delay_current != dialog->ms_delay)
            dialog->ms_delay_current = dialog->ms_delay;
        dialog->text_content[dialog->text_idx] = dialog->buffer[dialog->i];
        sfText_setString(dialog->text, dialog->text_content);
        push_word_to_new_line(dialog, window);
        skip_current_line(dialog, window);
        if (sound != NULL)
            sfSound_play(sound);
    }
}

void display_dialog(my_dialogbox *dialog, my_window *window)
{
    if (dialog->run) {
        if (dialog->mode == CINEMATIC &&
        sfRectangleShape_getOutlineThickness(dialog->gui) != 0)
            sfRectangleShape_setOutlineThickness(dialog->gui, 0);
        if (dialog->mode == DISCUSSION &&
        sfRectangleShape_getOutlineThickness(dialog->gui) == 0)
            sfRectangleShape_setOutlineThickness(dialog->gui,
            dialog->thickness);
        sfRenderWindow_drawRectangleShape(window->renderer, dialog->gui, NULL);
        sfRenderWindow_drawText(window->renderer, dialog->text, NULL);
        if (dialog->display_triangle && dialog->triangle_visibility) {
            update_triangle(dialog);
            sfRenderWindow_drawVertexArray(window->renderer,
            dialog->wait_triangle, NULL);
        }
    }
}
