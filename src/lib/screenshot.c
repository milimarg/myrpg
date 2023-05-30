/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** screenshot
*/

#include "../../include/my_rpg/my_rpg.h"

sfImage *take_screenshot(sfRenderWindow *window)
{
    return (sfRenderWindow_capture(window));
}
