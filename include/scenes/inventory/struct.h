/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** struct
*/

#ifndef STRUCT_INVENTORY_H_
    #define STRUCT_INVENTORY_H_
    #define CAST_INVENTORY(inventory) (inventory_scene *)(inventory)
typedef struct inventory_scene {
    sfVector2u slot_texture_size;
    my_container *container;
    sfRectangleShape *filter;
    sfRectangleShape **slot_hitbox;
    int item_floating;
    items_list *selected_item;
    int selected_item_index;
    sfSprite *sprite;
    sfVector2f sprite_pos;
    int anti_spam_mouse;
    int current_coins_nb;
} inventory_scene;
#endif /* !STRUCT_INVENTORY_H_ */
