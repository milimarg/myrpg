/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** prototype
*/

#ifndef PROTOTYPE_SHOP_H_
    #define PROTOTYPE_SHOP_H_
shop_t *create_shop(unsigned int max_items_nb, char *selection_item_name_tag,
my_textures_list *list);
void add_item_to_shop(shop_t *shop, item_infos *item_info,
my_textures_list *list);
void set_shop_appearance(shop_t *shop, unsigned int outline_thickness,
sfColor bg_color, sfColor outline_color);
void display_shop(shop_t *shop, my_window *window);
void move_selection_shop(shop_t *shop);
void give_item_from_shop(shop_t *shop, my_dialogbox *dialog,
inventory_scene *inv, my_textures_list *list);
void set_shop_items_rect(shop_t *shop, sfIntRect *rect, sfFont *font);
void set_shop_greeting_rect(shop_t *shop, sfVector2f *pos, sfFont *font,
my_textures_list *list);
void set_item_position_inventory(inventory_scene *inv);
void set_item_position_shop(inventory_scene *inv, shop_t *shop);
int find_item_in_container(my_container *container, char *display_name);
#endif /* !PROTOTYPE_SHOP_H_ */
