/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** parsing_map
*/

#include "../../include/my_rpg/my_rpg.h"

void set_map_texture(map_t *map, char *display_name,
my_textures_list *temp)
{
    sfVector2f pos = {map->rect.left, map->rect.top};
    sfVector2f text_pos = {map->rect.left, map->rect.top};
    sfVector2f size = {map->rect.width, map->rect.height};

    map->texture = temp->texture;
    map->sprite = sfSprite_create();
    sfSprite_setTexture(map->sprite, map->texture, sfTrue);
    sfSprite_setPosition(map->sprite, pos);
}

map_t *add_map(sfIntRect *rectangle, char **name_tag_and_display_name,
my_textures_list *textures_list)
{
    map_t *map = NULL;

    for (my_textures_list *temp = textures_list; temp; temp = temp->next) {
        if (!my_strcmp(temp->name_tag, name_tag_and_display_name[0])) {
            map = malloc(sizeof(map_t));
            map->rect = *rectangle;
            set_map_texture(map, name_tag_and_display_name[1], temp);
            break;
        }
    }
    return (map);
}

void parsing_map_ext(game_t *game, char **tab_arg, char *image_filepath)
{
    char **name_tag_and_name = malloc(sizeof(char *) * (2));
    map_t *map = NULL;

    name_tag_and_name[0] = tab_arg[6];
    map = add_map(&(sfIntRect) {my_getnbr(tab_arg[2]), my_getnbr(tab_arg[3]),
    my_getnbr(tab_arg[4]), my_getnbr(tab_arg[5])}, name_tag_and_name,
    game->textures_list);
    if (my_getnbr(tab_arg[7])) {
        map->image = sfImage_createFromFile(my_strcat(my_strcat
        (my_strcat(image_filepath, "./assets/images"), tab_arg[8]), "\0"));
    }
    add_to_object_list(game, init_object(map, MAP, tab_arg[1]), MAP);
}

int parsing_map(game_t *game, char **tab_arg, char *filepath)
{
    int len = 0;
    int size_image_filepath = 0;
    char *image_filepath = NULL;

    if (my_getnbr(tab_arg[7])) {
        size_image_filepath = my_strlen("./assets/images/")
        + my_strlen(tab_arg[8]) + 1;
        image_filepath = malloc(sizeof(char) * (size_image_filepath));
        my_extra_char_memset(image_filepath, '\0', size_image_filepath);
    }
    for (; tab_arg[len] != NULL; len++);
    if (len != 9 && len != 8) {
        write(2, filepath, my_strlen(filepath));
        write(2, ": wrong file\n", 13);
        return (84);
    }
    parsing_map_ext(game, tab_arg, image_filepath);
    return (0);
}
