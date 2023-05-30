/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** read_line.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include "dialogbox.h"

void read_line(my_dialogbox *dialog, int run_function, ssize_t *output)
{
    int buffer_len = 0;

    if (((run_function || !dialog->is_begin_of_dialog) && dialog->run &&
        !dialog->clicked && !dialog->reading)) {
        dialog->clicked = 1;
        dialog->skip_delay = 0;
        *output = getline(&dialog->buffer, &dialog->getline_bytes, dialog->fd);
        if (*output != -1) {
            dialog->reading = 1;
            buffer_len = extra_my_strlen(dialog->buffer);
            free(dialog->text_content);
            dialog->text_content = malloc(sizeof(char) * (buffer_len + 101));
            my_extra_char_memset(dialog->text_content, 0, buffer_len + 101);
        }
    }
}
