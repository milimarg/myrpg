/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** object_list
*/

#include "../../include/my_rpg/my_rpg.h"

void clear_object_list(game_t *game)
{
    linked_list_object_t *temp = NULL;
    linked_list_object_t *list = game->current_scene->object_list;

    while (list != NULL) {
        temp = list->next;
        list->object->destroy(list->object->struct_type, game);
        free(list->object);
        free(list);
        list = temp;
    }
    game->current_scene->object_list = NULL;
}

object_t *find_in_object_list(game_t *game, char *id)
{
    for (linked_list_object_t *temp = game->current_scene->object_list;
    temp != NULL; temp = temp->next) {
        if (my_strcmp(temp->object->id, id) == 0) {
            return (temp->object);
        }
    }
    return (NULL);
}

linked_list_object_t *find_list_elem_in_object_list(game_t *game, char *id)
{
    for (linked_list_object_t *temp = game->current_scene->object_list;
    temp != NULL; temp = temp->next) {
        if (my_strcmp(temp->object->id, id) == 0) {
            return (temp);
        }
    }
    return (NULL);
}
