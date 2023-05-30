/*
** EPITECH PROJECT, 2023
** my_csfml_container
** File description:
** dropdown_utils.c
*/

#include <SFML/Graphics.h>
#include "../window/window.h"
#include "button.h"

void update_dropdown_state(my_window *window, my_dropdown *dp)
{
    sfFloatRect rect = sfRectangleShape_getLocalBounds(dp->shape);
    sfVector2i pos = sfMouse_getPositionRenderWindow(window->renderer);
    int hover_status = sfFloatRect_contains(&rect, pos.x, pos.y);
    int click_status = sfMouse_isButtonPressed(sfMouseLeft);

    if (!hover_status && !click_status)
        dp->state = NONE;
    if (hover_status && !click_status)
        dp->state = HOVER;
    if (hover_status && click_status)
        dp->state = CLICKED;
}
