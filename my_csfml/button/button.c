/*
** EPITECH PROJECT, 2023
** my_csfml
** File description:
** buttons
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "button.h"
#include "../lib.h"

my_button **init_buttons_array(unsigned int buttons_number)
{
    my_button **buttons = malloc(sizeof(my_button *) * (buttons_number + 1));

    return (buttons);
}

static void set_button_texture(my_button *button, char *display_name,
my_textures_list *temp)
{
    sfVector2f pos = {button->rect.left, button->rect.top};
    sfVector2f text_pos = {button->rect.left, button->rect.top};

    button->texture = temp->texture;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setPosition(button->sprite, pos);
    button->text = sfText_create();
    sfText_setPosition(button->text, text_pos);
    sfText_setString(button->text, display_name);
    sfText_setCharacterSize(button->text, 25);
}

my_button* add_button(sfIntRect *rectangle, char **name_tag_and_display_name,
void (*function)(void *values), my_textures_list *textures_list)
{
    my_button *button = NULL;

    for (my_textures_list *temp = textures_list; temp; temp = temp->next) {
        if (!extra_my_strcmp(temp->name_tag, name_tag_and_display_name[0])) {
            button = malloc(sizeof(my_button));
            button->rect = *rectangle;
            button->function = function;
            set_button_texture(button, name_tag_and_display_name[1], temp);
            button->state = NONE;
            return (button);
        }
    }
    write(2, "button: texture not found\n", 26);
    return (NULL);
}

int destroy_buttons_array(my_button **buttons)
{
    for (int i = 0; buttons[i] != NULL; i++) {
        sfSprite_destroy(buttons[i]->sprite);
        sfText_destroy(buttons[i]->text);
        free(buttons[i]);
    }
    free(buttons);
    return (0);
}

void display_buttons(my_button **buttons, my_window *window)
{
    for (int i = 0; buttons[i] != NULL; i++) {
        sfRenderWindow_drawSprite(window->renderer, buttons[i]->sprite, NULL);
    }
}
