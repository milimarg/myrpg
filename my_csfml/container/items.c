/*
** EPITECH PROJECT, 2023
** my_csfml_container
** File description:
** items
*/

#include <stdlib.h>
#include <unistd.h>
#include "container.h"

static int skip_forbidden_slot(int *index, item_infos *infos,
my_container *container)
{
    if (*index == 0 && infos->type == SWORD &&
        container->items[*index]->empty)
        return (1);
    if (*index == 1 && infos->type == NECKLACE &&
        container->items[*index]->empty)
        return (1);
    if (*index > 1 && container->items[*index]->empty)
        return (1);
    (*index)++;
    return (0);
}

int add_item(my_container *container, item_infos *infos,
my_textures_list *textures_list)
{
    int index = 0;
    int empty_slots_nb = 0;

    for (int i = 0; i < container->max_items_nb; i++)
        if (container->items[i]->empty)
            empty_slots_nb++;
    if (container->current_items_nb == container->max_items_nb ||
    empty_slots_nb == 0) {
        write(2, "my_container: cannot add item, inventory full\n", 46);
        return (84);
    }
    container->current_items_nb++;
    while (index < container->max_items_nb) {
        if (skip_forbidden_slot(&index, infos, container))
            break;
    }
    container->items[index]->infos = *infos;
    container->items[index]->empty = 0;
    container->last_index = index;
    return (set_item_texture(container->items[index], textures_list));
}

void remove_item(my_container *container, unsigned int index)
{
    if (container->items[index]->empty) {
        write(2, "container: cannot remove item, item doesn't exist\n", 50);
        return;
    }
    container->items[index]->infos = (item_infos){0};
    container->items[index]->floating = 0;
    container->items[index]->empty = 1;
    sfSprite_destroy(container->items[index]->sprite);
}
