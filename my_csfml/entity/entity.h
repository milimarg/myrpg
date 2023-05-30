/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** entity
*/

#ifndef ENTITY_H_
    #define ENTITY_H_
    #include <SFML/Graphics.h>
    #include "../window/window.h"
    #include "../animation/animation.h"
typedef struct my_entity {
    char *type;
    int is_clicked;
    int is_ready;
    my_animation *anim;
    sfVector2f position;
    double speed;
    double hp;
    double drop_rate;
    int timer;
    int timer_max;
} my_entity;

// @brief Init an entity.
// @param entity entity structure
// @param name_tag name_tag to match
// @param textures_list textures linked list
// @param sprites_nb number of sprites in image
my_entity *spawn_entity(my_textures_list *head, char *name_tag,
double timer_max);

// @brief Init first position of entity.
// @param x x-axis of position
// @param y y-axis of position
// @param angle of position
void set_spawnpoint(my_entity *entity, sfVector2f *spawnpoint, double angle);

// ...
int set_entity_animation(my_animation *anim, char *name_tag,
my_textures_list *head);

// @brief Move position of entity.
// @param entity entity structure
// @param x x offset of move
// @param y y offset of move
// @param angle angle offset of move
void move_entity(my_entity *entity, sfVector2f *move, double angle);

// @brief destroy an entity
// @param entity entity to destroy
void destroy_entity_lib(my_entity *entity);
#endif /* !ENTITY_H_ */
