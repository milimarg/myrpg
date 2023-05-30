/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** link_list_of_mob_move
*/

#include "../../include/entity/mob/mob.h"

void add_node(float x, float y, link_list_pos_t **head)
{
    link_list_pos_t *elt = malloc(sizeof(link_list_pos_t));
    link_list_pos_t *temp = *head;

    elt->x = x;
    elt->y = y;
    elt->next = NULL;
    if (temp != NULL) {
        for (; temp->next != NULL; temp = temp->next);
        temp->next = elt;
    } else
        *head = elt;
}

void remove_head(link_list_pos_t **head)
{
    link_list_pos_t *remove = NULL;
    link_list_pos_t *temp = *head;

    remove = *head;
    (*head) = (*head)->next;
    free(remove);
}

void remove_multiple_node(link_list_pos_t **head, float x, float y)
{
    link_list_pos_t *remove = NULL;
    link_list_pos_t *temp = *head;

    temp = temp->next;
    for (; temp != NULL; temp = temp->next) {
        if (temp->next != NULL && temp->next->x == x && temp->next->y == y) {
            remove = temp->next;
            temp->next = temp->next->next;
            free(remove);
            return;
        }
    }
}

void free_list(link_list_pos_t *head)
{
    link_list_pos_t *remove = NULL;

    while (head != NULL) {
        remove = head;
        head = head->next;
        free(remove);
    }
}
