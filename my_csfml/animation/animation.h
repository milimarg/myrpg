/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** animations
*/

#ifndef ANIMATIONS_H_
    #define ANIMATIONS_H_
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
typedef struct my_texture_rect {
    int left;
    int top;
    int width;
    int height;
    int moves_nb;
} my_texture_rect;
typedef struct my_animation {
    int i;
    int move_nb;
    char *path;
    int has_sprite_been_defined;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect full_texture_rect;
    sfIntRect one_texture_rect;
} my_animation;
typedef struct my_textures_list {
    char *name_tag;
    char *path;
    sfIntRect rect;
    sfTexture *texture;
    int moves_nb;
    struct my_textures_list *next;
} my_textures_list;
typedef struct sprite_sizes {
    int width;
    int height;
    sfIntRect *texture_rect;
} sprite_sizes;

// @brief Init a textures list.
// @return A NULL pointer to init the linked list.
my_textures_list *init_textures_list(void);

// @brief Link an image to a nametag, create a texture from the image and add
// it in the linked list.
// @param textures_list textures linked list
// @param name_tag nametag to check
// @param path path of image
// @param sfIntRect rectangle to apply
void add_texture(my_textures_list **textures_list, char *name_tag, char *path,
my_texture_rect *rect);

// @brief Update animation of one movement.
// @param anim animation structure
void update_animation(my_animation *anim);

// @brief Update animation backwards of one movement.
// @param anim animation structure
void update_animation_reverse(my_animation *anim);

// @brief Reset the current animation
// @param anim animation structure
void reset_entity_animation(my_animation *anim);

// @brief Reset the current animation backwards
// @param anim animation structure
void reset_entity_animation_reverse(my_animation *anim);

// @brief Destroy a textures list
// @param textures_list textures linked list to destroy
void destroy_textures_list(my_textures_list *textures_list);

// ...
my_textures_list *find_texture_in_list(my_textures_list *list, char *name_tag);
#endif /* !ANIMATIONS_H_ */
