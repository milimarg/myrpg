/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** button_functions
*/

#include "../../../include/my_rpg/my_rpg.h"

void draw_button(void *button_struct, game_t *game)
{
    my_button *button = CAST_BUTTON(button_struct);

    sfRenderWindow_drawSprite(game->win->renderer, button->sprite, NULL);
}

void update_button(void *button_struct, game_t *game)
{
    my_button *button = CAST_BUTTON(button_struct);

    sfSprite_setPosition(button->sprite,
    (sfVector2f){button->rect.left
    / game->win->ratio.x, button->rect.top / game->win->ratio.y});
    sfSprite_setScale(button->sprite,
    (sfVector2f){1 / game->win->ratio.x, 1 / game->win->ratio.y});
    if (button->texture == find_texture_in_list(game->textures_list,
    "locked_continue_button")->texture) {
        return;
    }
    if (IS_HOVER(button->state))
        sfSprite_setColor(button->sprite, button->hover_color);
    if (IS_CLICKED(button->state)) {
        sfSprite_setColor(button->sprite, button->click_color);
        button->function(game);
        button->state = RELEASED;
    }
    if (button->state == NONE)
        sfSprite_setColor(button->sprite, button->base_color);
}

void event_button(void *button_struct, sfEvent event, game_t *game)
{
    my_button *button = CAST_BUTTON(button_struct);

    sfFloatRect rect = sfSprite_getGlobalBounds(button->sprite);
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->win->renderer);
    int hover_status = sfFloatRect_contains(&rect, pos.x, pos.y);
    int click_status = 0;

    if (event.type == sfEvtMouseButtonPressed)
        click_status = 1;
    if (!hover_status && !click_status)
        button->state = NONE;
    if (hover_status && !click_status)
        button->state = HOVER;
    if (hover_status && click_status)
        button->state = CLICKED;
}

void timer_button(void *button_struct, game_t *game)
{

}

void destroy_button(void *button_struct, game_t *game)
{

}
