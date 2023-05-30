/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_object
*/

#include "../../include/my_rpg/my_rpg.h"
#include "../../include/scenes/inventory/prototype.h"

object_t *init_object(void *object_struct, object_type type, char *id)
{
    object_t *object = malloc(sizeof(object_t));

    object->draw = OBJECT_DRAW_TAB[type];
    object->update = OBJECT_UPDATE_TAB[type];
    object->event = OBJECT_EVENT_TAB[type];
    object->timer = OBJECT_TIMER_TAB[type];
    object->destroy = OBJECT_DESTROY_TAB[type];
    object->struct_type = object_struct;
    object->type = type;
    object->id = id;
    return (object);
}
