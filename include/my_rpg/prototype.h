/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** prototype
*/

#ifndef PROTOTYPE_MY_RPG_H_
    #define PROTOTYPE_MY_RPG_H_
    #include "my_rpg.h"

void update(game_t *game);
void timer(game_t *game);
void game_loop(game_t *game);
void event(game_t *game);
void draw(game_t *game);

void set_player_position(game_t *game, linked_list_object_t *list);
void init_quests(game_t *game);
player_t *init_player(game_t *game);
void init_inventory_object(game_t *game);
void init_textures(game_t *game);
void splash_screen(sfRenderWindow *window);
void init_sounds(sounds_t *sounds);
void init_texts(game_t *game);
sfBool init_save_state(game_t *game);
void init_game_loop(game_t *game);
void add_ui_to_list(game_t *game);
void update_player_hp_display(game_t *game);
void reset_scene_coord_pos(game_t *game);
void set_view_to_coord_pos(game_t *game);
void update_scene_coord_pos(game_t *game, float y_off, float x_off);
void init_scene_coord_pos(game_t *game);
void init_scene(game_t *game, char *id, scene_type type);
void switch_scene(game_t *game, scene_type type, char *id);
void add_to_object_list(game_t *game, object_t *object, object_type type);
void add_to_object_list_end(game_t *game, object_t *object, object_type type);
void add_to_object_list_after_map(game_t *game, object_t *object,
object_type type);
object_t *init_object(void *object_struct, object_type object, char *id);
void clear_object_list(game_t *game);
object_t *find_in_object_list(game_t *game, char *id);
linked_list_object_t *find_list_elem_in_object_list(game_t *game, char *id);
void grey_image(sfImage *image);
void for_one_parsing(char **temp_filepath_cut, char **dialog_path,
char *path_gene, int len_path_gene);
void first_function(char **path_gene, char ** temp_filepath_cut,
int *len_path_gene, char **tab_arg);

void draw_button(void *button_struct, game_t *game);
void update_button(void *button_struct, game_t *game);
void event_button(void *button_struct, sfEvent Event, game_t *game);
void destroy_button(void *button_struct, game_t *game);
void timer_button(void *button_struct, game_t *game);

void draw_map(void *data, game_t *game);
void update_map(void *data, game_t *game);
void event_map(void *data, sfEvent Event, game_t *game);
void destroy_map(void *data, game_t *game);
void timer_map(void *data, game_t *game);

void draw_inventory(void *data, game_t *game);
void update_inventory(void *data, game_t *game);
void event_inventory(void *data, sfEvent Event, game_t *game);
void destroy_inventory(void *data, game_t *game);
void timer_inventory(void *data, game_t *game);

void draw_pause(void *data, game_t *game);
void update_pause(void *data, game_t *game);
void event_pause(void *data, sfEvent event, game_t *game);
void destroy_pause(void *data, game_t *game);
void timer_pause(void *data, game_t *game);

void draw_start_cinematic(void *data, game_t *game);
void update_start_cinematic(void *data, game_t *game);
void event_start_cinematic(void *data, game_t *game);
void destroy_start_cinematic(void *data, game_t *game);
void timer_start_cinematic(void *data, game_t *game);

void draw_tp(void *data, game_t *game);
void update_tp(void *data, game_t *game);
void event_tp(void *data, sfEvent Event, game_t *game);
void destroy_tp(void *data, game_t *game);
void timer_tp(void *data, game_t *game);

void draw_npc(void *data, game_t *game);
void update_npc(void *data, game_t *game);
void event_npc(void *data, sfEvent Event, game_t *game);
void destroy_npc(void *data, game_t *game);
void timer_npc(void *data, game_t *game);

void draw_maze3d(void *data, game_t *game);
void update_maze3d(void *data, game_t *game);
void event_maze3d(void *data, sfEvent Event, game_t *game);
void destroy_maze3d(void *data, game_t *game);
void timer_maze3d(void *data, game_t *game);

void draw_mob(void *data, game_t *game);
void update_mob(void *data, game_t *game);
void event_mob(void *data, sfEvent Event, game_t *game);
void destroy_mob(void *data, game_t *game);
void timer_mob(void *data, game_t *game);

void draw_map_night(void *data, game_t *game);
void update_map_night(void *data, game_t *game);
void event_map_night(void *data, sfEvent Event, game_t *game);
void destroy_map_night(void *data, game_t *game);
void timer_map_night(void *data, game_t *game);

void timer_image(void *data, game_t *game);
void destroy_image(void *data, game_t *game);
void event_image(void *data, sfEvent Event, game_t *game);
void update_image(void *data, game_t *game);
void draw_image(void *data, game_t *game);

void timer_entity(void *data, game_t *game);
void destroy_entity(void *data, game_t *game);
void event_entity(void *data, sfEvent Event, game_t *game);
void update_entity(void *data, game_t *game);
void draw_entity(void *data, game_t *game);

void timer_shop(void *data, game_t *game);
void destroy_shop(void *data, game_t *game);
void event_shop(void *data, sfEvent Event, game_t *game);
void update_shop(void *data, game_t *game);
void draw_shop(void *data, game_t *game);

void event_text(void *data, sfEvent Event, game_t *game);
void update_text(void *data, game_t *game);
void draw_text(void *data, game_t *game);
void destroy_text(void *data, game_t *game);
void timer_text(void *data, game_t *game);

void update_throne_room(game_t *game);

void init_main_map(game_t *game);
void init_main_menu(game_t *game);
void init_settings(game_t *game);
void init_cave(game_t *game);
void init_no_scene(game_t *game);
void init_no_scene(game_t *game);
void init_death(game_t *game);
void init_tavern(game_t *game);
void init_shop(game_t *game);
void init_pause(game_t *game);
void init_maze(game_t *game);
void init_magic_tower(game_t *game);
void init_jail(game_t *game);
void init_castle(game_t *game);
void init_inventory(game_t *game);
void init_pause(game_t *game);
void init_start_cinematic(game_t *game);
void init_maze3d(game_t *game);
void init_main_map_night(game_t *game);
void init_jewels_room(game_t *game);
void init_throne_room(game_t *game);
void init_blacksmith(game_t *game);
void init_end(game_t *game);

void update_main_night(game_t *game);
void update_castle(game_t *game);
void take_flower(game_t *game);
void remove_flowers(game_t *game);

void move_player(game_t *game);
void update_player_texture(game_t *game, char *anim_names[], int i);
int check_collisions(map_t *map, sfVector2u *pos);

void save(game_t *game);
void load_save(game_t *game);

sfImage *take_screenshot(sfRenderWindow *window);

void move_mob_tavern(game_t *game, mob_t *mob);

void init_castle_action(game_t *);
void init_cave_action(game_t *);
void init_inventory_action(game_t *);
void init_magic_tower_action(game_t *);
void init_main_menu_action(game_t *);
void init_maze_action(game_t *);
void init_maze3d_action(game_t *);
void init_pause_action(game_t *);
void init_settings_action(game_t *);
void init_tavern_action(game_t *);
void init_shop_action(game_t *);
void init_jail_action(game_t *);
void init_death_action(game_t *);
void init_end_action(game_t *game);
void init_jewels_room_action(game_t *);
void init_main_map_action(game_t *);
void init_start_cinematic_action(game_t *);
void init_main_map_night_action(game_t *);
void init_throne_room_action(game_t *game);
void init_blacksmith_action(game_t *game);

#endif /* !PROTOTYPE_MY_RPG_H_ */
