/*
** EPITECH PROJECT, 2023
** my_csfml_container
** File description:
** container.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "container.h"

my_container *init_container(char *display_name, unsigned int max_items_nb,
unsigned int width_len)
{
    my_container *container = NULL;

    container = malloc(sizeof(my_container));
    container->display_name = display_name;
    container->current_items_nb = 0;
    container->max_items_nb = max_items_nb;
    container->items = NULL;
    container->width_len = width_len;
    container->items = malloc(sizeof(items_list *) * (max_items_nb + 1));
    for (int i = 0; i < max_items_nb; i++) {
        container->items[i] = malloc(sizeof(items_list));
        container->items[i]->empty = 1;
        container->items[i]->sprite = NULL;
        container->items[i]->floating = 0;
    }
    container->items[max_items_nb] = NULL;
    return (container);
}

void destroy_container(my_container *container)
{
    items_list *temp = NULL;

    for (int i = 0; i < container->max_items_nb; i++) {
        sfSprite_destroy(container->items[i]->sprite);
        free(container->items[i]);
    }
    free(container->items);
    free(container);
}
