/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** dialog_mode.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "dialogbox.h"

void set_dialog_mode(my_dialogbox *dialog, dialog_mode mode)
{
    if (dialog->mode != mode)
        dialog->mode = mode;
}
