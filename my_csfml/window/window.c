/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** window
*/

#include <stdlib.h>
#include "window.h"

my_window *create_window(char *title, sfVector2u *window_size, unsigned int fps)
{
    my_window *window = malloc(sizeof(my_window));

    window->width = window_size->x;
    window->height = window_size->y;
    window->bitsPerPixel = 32;
    window->renderer = sfRenderWindow_create(
    (sfVideoMode){window->width, window->height, window->bitsPerPixel}, title,
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window->renderer, fps);
    window->clock = sfClock_create();
    return (window);
}

sfVector2u update_window_ratio(my_window *window)
{
    sfVector2u size = sfRenderWindow_getSize(window->renderer);

    window->ratio.x = (double)window->width / (double)size.x;
    window->ratio.y = (double)window->height / (double)size.y;
    return (size);
}
