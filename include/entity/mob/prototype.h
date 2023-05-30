/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** prototype
*/

#ifndef PROTOTYPE_MOB_H_
    #define PROTOTYPE_MOB_H_
    #include "struct.h"
    #include "../../my_rpg/my_rpg.h"

void add_node(float x, float y, link_list_pos_t **head);
void remove_head(link_list_pos_t **head);
void free_list(link_list_pos_t *head);
mob_t *init_mob(game_t *game, char **tab_arg);
my_entity *fill_mob_entity(mob_t *mob, char *name_tag,
my_textures_list *textures_list, my_entity **entity);
void set_mob_origin_scale(mob_t *mob, sfVector2f origin);
void remove_multiple_node(link_list_pos_t **head, float x, float y);
void change_mob_side(mob_t *mob);
void manage_timer_mob(game_t *game, mob_t *mob);
void manage_run_mob(game_t *game, mob_t *mob);
void mob_attack(game_t *game, mob_t *mob);
int collision_up(sfVector2f *mob_pos, mob_t *mob, sfImage *image, int i);
void update_mob_tavern_up(sfVector2f *mob_pos, game_t *game, mob_t *mob,
sfImage *image);
void update_mob_tavern_down(sfVector2f *mob_pos, game_t *game, mob_t *mob,
sfImage *image);
void update_mob_tavern_left(sfVector2f *mob_pos, game_t *game, mob_t *mob,
sfImage *image);
void update_mob_tavern_right(sfVector2f *mob_pos, game_t *game, mob_t *mob,
sfImage *image);
#endif /* !PROTOTYPE_MOB_H_ */
