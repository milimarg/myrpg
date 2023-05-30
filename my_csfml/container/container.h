/*
** EPITECH PROJECT, 2023
** my_csfml
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_
    #include <SFML/System.h>
    #include "../animation/animation.h"
typedef enum item_type_inventory {
    SWORD = 0,
    NECKLACE,
    COMMON
} item_type_inventory;
typedef struct item_infos {
    char *name_tag;
    char *display_name;
    char *dialog_path;
    int quantity;
    char *price;
    item_type_inventory type;
} item_infos;
typedef struct items_list {
    item_infos infos;
    int empty;
    int floating;
    sfSprite *sprite;
    sfText *display_text;
    sfSprite *money_sprite;
    sfText *quantity_text;
} items_list;
typedef struct my_container {
    char *display_name;
    int current_items_nb;
    int max_items_nb;
    int width_len;
    int last_index;
    items_list **items;
} my_container;

int set_item_texture(items_list *new_item, my_textures_list *textures_list);

// @brief Init a container.
// @param type type of container ('I' for inventory and 'C' for container)
// @param display_name name to display
// @param max_items_nb max number of items that can be added to the container
my_container *init_container(char *display_name, unsigned int max_items_nb,
unsigned int width_len);

// @brief Destroy a container.
// @param container container structure
void destroy_container(my_container *container);

// @brief Add an item to a container.
// @param container container structure
// @param name_tag name_tag to match for texture
// @param display_name name to display
// @param textures_list textures linked list
// @return 84 on error
int add_item(my_container *container, item_infos *infos,
my_textures_list *textures_list);

// ...
void remove_item(my_container *container, unsigned int index);
#endif /* !INVENTORY_H_ */
