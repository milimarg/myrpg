/*
** EPITECH PROJECT, 2023
** my_csfml_container
** File description:
** items_utils
*/

#include <unistd.h>
#include "container.h"
#include "../lib.h"

int set_item_texture(items_list *new_item, my_textures_list *textures_list)
{
    my_textures_list *to_match = NULL;

    to_match = find_texture_in_list(textures_list, new_item->infos.name_tag);
    if (to_match == NULL) {
        write(2, "my_container: cannot find texture of item\n", 42);
        return (84);
    }
    new_item->sprite = sfSprite_create();
    sfSprite_setTexture(new_item->sprite, to_match->texture, sfTrue);
    return (0);
}
