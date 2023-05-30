/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** dialog_utils.c
*/

#include <stdio.h>
#include <unistd.h>
#include "dialogbox.h"

int check_if_char_is_punctuation(my_dialogbox *dialog)
{
    for (int i = 0; dialog->punc_array[i] != '\0'; i++) {
        if (dialog->buffer[dialog->i] == dialog->punc_array[i] &&
            dialog->ms_delay_current != dialog->ms_delay_punc) {
            dialog->ms_delay_current = dialog->ms_delay_punc;
            return (1);
        }
    }
    return (0);
}
