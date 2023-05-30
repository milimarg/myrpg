/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** shop.c
*/

#include "../../../include/my_rpg/my_rpg.h"
#include "../../../include/scenes/inventory/struct.h"

static void init_shop_items(shop_t *shop)
{
    for (int i = 0; i < shop->max_items_nb; i++) {
        shop->items[i].empty = 1;
        shop->items[i].sprite = sfSprite_create();
        shop->items[i].display_text = sfText_create();
    }
}

shop_t *create_shop(unsigned int max_items_nb, char *selection_item_name_tag,
my_textures_list *list)
{
    shop_t *shop = malloc(sizeof(shop_t));
    my_textures_list *to_match = NULL;

    shop->i = 0;
    shop->max_items_nb = max_items_nb;
    shop->items = malloc(sizeof(items_list) * (shop->max_items_nb + 1));
    init_shop_items(shop);
    to_match = find_texture_in_list(list, selection_item_name_tag);
    if (to_match == NULL) {
        write(2, "shop error: selection item texture is not found\n", 48);
        return (NULL);
    }
    shop->selection_element_sprite = sfSprite_create();
    sfSprite_setTexture(shop->selection_element_sprite, to_match->texture, 1);
    sfSprite_setScale(shop->selection_element_sprite, (sfVector2f){0.5, 0.5});
    shop->anti_spam_mouse1 = 0;
    shop->anti_spam_mouse2 = 0;
    shop->anti_spam_enter = 0;
    shop->selected_item_index = 0;
    return (shop);
}

void set_shop_appearance(shop_t *shop, unsigned int outline_thickness,
sfColor bg_color, sfColor outline_color)
{
    shop->outline_thickness = outline_thickness;
    shop->bg_color = bg_color;
    shop->outline_color = outline_color;
}

int find_item_in_container(my_container *container, char *name_tag)
{
    for (int i = 0; i < container->max_items_nb; i++) {
        if (!container->items[i]->empty &&
        !my_strcmp(container->items[i]->infos.name_tag, name_tag)) {
            return (i);
        }
    }
    return (-1);
}
