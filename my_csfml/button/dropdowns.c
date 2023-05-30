/*
** EPITECH PROJECT, 2023
** my_csfml_container
** File description:
** dropdowns.c
*/

#include <stdlib.h>
#include "button.h"

static int set_dropdown_rectangle_shape(my_dropdown *dp)
{
    sfVector2f pos = {dp->rect.left, dp->rect.top};
    sfVector2f size = {dp->rect.width, dp->rect.height};

    dp->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(dp->shape, size);
    sfRectangleShape_setOutlineColor(dp->shape, dp->color);
    sfRectangleShape_setOutlineThickness(dp->shape, 1);
    sfRectangleShape_setFillColor(dp->shape, dp->color);
    sfRectangleShape_setPosition(dp->shape, pos);
    return (0);
}

my_dropdown *init_dropdown(sfIntRect *rectangle, sfColor *color,
my_button **buttons, char *display_name)
{
    my_dropdown *element = malloc(sizeof(my_dropdown));

    element->rect = *rectangle;
    element->color = *color;
    element->state = NONE;
    element->buttons = buttons;
    set_dropdown_rectangle_shape(element);
    element->text = sfText_create();
    sfText_setString(element->text, display_name);
    return (element);
}

int destroy_dropdown(my_dropdown *dp)
{
    sfRectangleShape_destroy(dp->shape);
    sfText_destroy(dp->text);
    free(dp);
    return (0);
}

void display_dropdown(my_dropdown *dp, my_window *window)
{
    sfRenderWindow_drawText(window->renderer, dp->text, NULL);
    sfRenderWindow_drawRectangleShape(window->renderer, dp->shape, NULL);
}
