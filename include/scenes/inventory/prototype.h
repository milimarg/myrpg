/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** prototype
*/

#ifndef PROTOTYPE_INVENTORY_H_
    #define PROTOTYPE_INVENTORY_H_
void draw_inventory(void *data, game_t *game);
void update_inventory(void *data, game_t *game);
void event_inventory(void *data, sfEvent Event, game_t *game);
void destroy_inventory(void *data, game_t *game);
void timer_inventory(void *data, game_t *game);
int detect_items_inventory(inventory_scene *inventory, int i,
sfVector2i *mouse);
#endif /* !PROTOTYPE_INVENTORY_H_ */
