/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** add_to_object_list
*/

#include "../../include/my_rpg/my_rpg.h"

void add_to_object_list(game_t *game, object_t *object, object_type type)
{
    linked_list_object_t *new_node = malloc(sizeof(linked_list_object_t));

    new_node->next = game->current_scene->object_list;
    game->current_scene->object_list = new_node;
    new_node->object = object;
}

void add_to_object_list_end(game_t *game, object_t *object, object_type type)
{
    linked_list_object_t *new_node = malloc(sizeof(linked_list_object_t));
    linked_list_object_t *temp = game->current_scene->object_list;

    for (; temp->next != NULL; temp = temp->next);
    new_node->object = object;
    temp->next = new_node;
    new_node->next = NULL;
}

void add_to_object_list_after_map(game_t *game, object_t *object,
object_type type)
{
    linked_list_object_t *new_node = malloc(sizeof(linked_list_object_t));
    linked_list_object_t *temp = game->current_scene->object_list;

    for (; temp->next != NULL && my_strcmp(temp->object->id, "map")
    != 0; temp = temp->next);
    new_node->object = object;
    new_node->next = temp->next;
    temp->next = new_node;
}
