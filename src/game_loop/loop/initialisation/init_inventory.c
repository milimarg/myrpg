/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_inventory
*/

#include "../../../../include/my_rpg/my_rpg.h"
#include "../../../../include/scenes/inventory/struct.h"

void init_inventory_object_set_squares(inventory_scene *inventory)
{
    sfVector2u index = {0, 0};
    sfVector2f pos = {0};
    sfVector2f inventory_start = sfSprite_getPosition(inventory->sprite);
    sfVector2f st = {inventory_start.x + 614, inventory_start.y + 300};
    sfVector2f shi = {93, 97};

    for (int i = 2; i < inventory->container->max_items_nb; i++) {
        inventory->slot_hitbox[i] = sfRectangleShape_create();
        if ((i - 2) % inventory->container->width_len == 0 && (i - 2) != 0) {
            index.y++;
            index.x = 0;
        }
        pos = (sfVector2f){st.x + (shi.x * index.x), st.y + (shi.y * index.y)};
        sfRectangleShape_setSize(inventory->slot_hitbox[i],
        (sfVector2f){inventory->slot_texture_size.x,
        inventory->slot_texture_size.y});
        sfRectangleShape_setPosition(inventory->slot_hitbox[i], pos);
        sfRectangleShape_setFillColor(inventory->slot_hitbox[i], sfGreen);
        index.x++;
    }
}

void init_inventory_object_values(inventory_scene *inventory, game_t *game,
sfVector2f texture_size)
{
    sfSprite_setPosition(inventory->sprite, (sfVector2f){(game->win->width
    - texture_size.x) / 2, (game->win->height - texture_size.y) / 2 - 50});
    sfRectangleShape_setSize(inventory->filter,
    (sfVector2f){game->win->width, game->win->height});
    sfRectangleShape_setFillColor(inventory->filter, game->filter_color);
    inventory->slot_hitbox = malloc(sizeof(sfRectangleShape *)
    * inventory->container->max_items_nb);
    sfVector2f pos_body[2] = {{515, 735}, {675, 735}};
    for (int i = 0; i < 2; i++) {
        inventory->slot_hitbox[i] = sfRectangleShape_create();
        sfRectangleShape_setSize(inventory->slot_hitbox[i],
        (sfVector2f){inventory->slot_texture_size.x,
        inventory->slot_texture_size.y});
        sfRectangleShape_setPosition(inventory->slot_hitbox[i], pos_body[i]);
        sfRectangleShape_setFillColor(inventory->slot_hitbox[i], sfGreen);
    }
    init_inventory_object_set_squares(inventory);
}

static void fill_inventory_variables(inventory_scene *inventory, game_t *game,
my_textures_list *my_texture)
{
    sfVector2f texture_size = (sfVector2f){my_texture->rect.width,
    my_texture->rect.height};

    inventory->slot_texture_size = (sfVector2u){70, 70};
    inventory->container = init_container("Player's Inventory", 26, 6);
    inventory->filter = sfRectangleShape_create();
    inventory->slot_hitbox = NULL;
    inventory->item_floating = 0;
    inventory->selected_item = NULL;
    inventory->selected_item_index = 0;
    inventory->sprite = sfSprite_create();
    inventory->sprite_pos = (sfVector2f){(game->win->width - texture_size.x)
    / 2, (game->win->height - texture_size.y) / 2 - 50};
    inventory->anti_spam_mouse = 0;
    inventory->current_coins_nb = 0;
    sfSprite_setTexture(inventory->sprite, my_texture->texture, sfTrue);
    init_inventory_object_values(inventory, game, texture_size);
}

void init_inventory_object(game_t *game)
{
    inventory_scene *inventory = malloc(sizeof(inventory_scene));
    my_textures_list *my_texture =
    find_texture_in_list(game->textures_list, "inventory");
    sfVector2f texture_size = {0};
    my_texture = find_texture_in_list(game->textures_list, "inventory");
    if (my_texture == NULL) {
        write(2, "init_inventory: cannot access to texture\n", 41);
        return;
    }
    fill_inventory_variables(inventory, game, my_texture);
    game->inventory_object = init_object(inventory, INVENTORY_OBJECT,
    "inventory_object");
}
