/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** update_pick_up_settings
*/

#include "../../../include/my_rpg/my_rpg.h"

void update_pick_up_settings_ext(game_t *game, my_button *button,
sfColor color, int *antispam)
{
    sfSprite_setColor(button->sprite, color);
    for (int i = 0; i < sfKeyCount; i++) {
        if (sfKeyboard_isKeyPressed(i)) {
            game->keys[game->pick_up_index] = i;
            game->pick_up_mode_settings = 0;
            (*antispam) = 0;
            color.a = 255;
            sfSprite_setColor(button->sprite, color);
            return;
        }
    }
}

void update_pick_up_settings(game_t *game)
{
    static int antispam = 0;
    object_t *object = NULL;
    static my_button *button = NULL;
    static sfColor color = {0};

    if (!antispam) {
        antispam = 1;
        object = find_in_object_list(game, keys_name[game->pick_up_index]);
        button = (my_button *)(object->struct_type);
        color = sfSprite_getColor(button->sprite);
        color.r = 50;
        color.g = 50;
        color.b = 50;
    }
    update_pick_up_settings_ext(game, button, color, &antispam);
}
