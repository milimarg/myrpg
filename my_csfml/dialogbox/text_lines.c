/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** text_lines.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include "dialogbox.h"

void push_word_to_new_line(my_dialogbox *dialog, my_window *window)
{
    int word_len = 0;
    sfFloatRect test = sfText_getGlobalBounds(dialog->text);

    if (test.left + test.width > window->width - dialog->inner_offset.x) {
        while (
        char_is_visible(dialog->text_content[dialog->text_idx - word_len]))
            word_len++;
        dialog->i -= word_len;
        for (int i = 0; i < word_len; i++)
            dialog->text_content[dialog->text_idx - i] = ' ';
        dialog->text_content[dialog->text_idx] = '\n';
    }
}

void skip_current_line(my_dialogbox *dialog, my_window *window)
{
    dialog->text_idx++;
    dialog->i++;
    if (sfKeyboard_isKeyPressed(dialog->key) && !dialog->clicked &&
        !dialog->skip_delay && dialog->mode == DISCUSSION) {
        dialog->skip_delay = 1;
        for (; dialog->buffer[dialog->i] != '\0'; dialog->i++) {
            dialog->text_content[dialog->text_idx] = dialog->buffer[dialog->i];
            sfText_setString(dialog->text, dialog->text_content);
            push_word_to_new_line(dialog, window);
            dialog->text_idx++;
        }
        update_triangle_pos(dialog);
        dialog->i = 0;
        dialog->text_idx = 0;
        dialog->reading = 0;
        dialog->clicked = 1;
    }
}

void play_first_dialog(my_dialogbox *dialog)
{
    if (dialog->run && !dialog->is_begin_of_dialog)
        dialog->is_begin_of_dialog = 1;
    if (!dialog->run && dialog->is_begin_of_dialog)
        dialog->is_begin_of_dialog = 0;
}

static void reset_values_dialog(my_dialogbox *dialog, size_t output)
{
    play_first_dialog(dialog);
    if (dialog->reading && dialog->buffer[dialog->i] == '\0') {
        dialog->reading = 0;
        update_triangle_pos(dialog);
        dialog->text_idx = 0;
    }
    if (!sfKeyboard_isKeyPressed(dialog->key) && dialog->run && dialog->clicked)
        dialog->clicked = 0;
    if (output == -1 && dialog->run) {
        close_dialog(dialog);
    }
}

void dialog_go_to_next_line(my_dialogbox *dialog, my_window *window,
double *delay_update_line)
{
    ssize_t output = 0;
    int run_function = 0;

    if (dialog->is_begin_of_dialog && dialog->mode == CINEMATIC &&
    dialog->buffer[dialog->i] == '\0') {
        if (*delay_update_line > ((double)dialog->ms_wait_delay / 1000.0)) {
            *delay_update_line = 0;
            run_function = 1;
            dialog->i = 0;
            dialog->text_idx = 0;
        }
    }
    if (dialog->is_begin_of_dialog && dialog->mode == DISCUSSION &&
    sfKeyboard_isKeyPressed(dialog->key)) {
        run_function = 1;
        dialog->i = 0;
        dialog->text_idx = 0;
    }
    read_line(dialog, run_function, &output);
    reset_values_dialog(dialog, output);
}
