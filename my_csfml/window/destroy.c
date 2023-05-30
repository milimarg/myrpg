/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** destroy
*/

#include <stdlib.h>
#include "window.h"

int destroy_window(my_window *window)
{
    sfRenderWindow_close(window->renderer);
    sfRenderWindow_destroy(window->renderer);
    sfClock_destroy(window->clock);
    free(window);
    return (0);
}

int destroy_background(my_background *background)
{
    sfSprite_destroy(background->sprite);
    free(background);
    return (0);
}
