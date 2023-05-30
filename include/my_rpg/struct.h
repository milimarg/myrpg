/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** struct
*/

#ifndef STRUCT_MY_RPG_H_
    #define STRUCT_MY_RPG_H_
    #include "my_rpg.h"
    #include "../scenes/struct.h"
    #include "./player/player.h"
    #include "../audio/struct.h"
    #include "../../include/scenes/maze/struct.h"

typedef enum object_type {
    BUTTON = 0,
    MAP,
    INVENTORY_OBJECT,
    PAUSE_OBJECT,
    START_CINEMATIC_OBJECT,
    TP,
    NPC,
    MAZE3D_OBJ,
    MOB,
    MAIN_MAP_NIGHT_OBJECT,
    IMAGE,
    ENTITY,
    SHOP_OBJECT,
    TEXT
} object_type;

typedef struct object_s {
    void *struct_type;
    void (*draw)(void *, game_t *);
    void (*update)(void *, game_t *);
    void (*event)(void *, sfEvent event, game_t *);
    void (*timer)(void *, game_t *);
    void (*destroy)(void *, game_t *);
    object_type type;
    char *id;
} object_t;

typedef struct linked_list_object_s {
    object_t *object;
    struct linked_list_object_s *next;
} linked_list_object_t;

typedef struct map_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfImage *image;
} map_t;

typedef struct tp_s {
    sfVector2i start;
    sfVector2i end;
    sfVector2i spawn_point;
    scene_type trigger_scene;
    scene_type scene_type_switch;
    int orientation;
} tp_t;

typedef struct npc_s {
    char *id;
    char **dialog_path;
    int dialog_index;
    my_entity *entity;
    sfSprite *talking_sprite;
} npc_t;

typedef struct shop_s {
    items_list *items;
    unsigned int i;
    unsigned int max_items_nb;
    unsigned int outline_thickness;
    int selected_item_index;
    int anti_spam_mouse1;
    int anti_spam_mouse2;
    int anti_spam_enter;
    sfRectangleShape *item_area;
    sfRectangleShape *greeting_message_area;
    sfIntRect item_area_rect;
    sfIntRect greeting_rect;
    sfColor bg_color;
    sfColor outline_color;
    sfSprite *selection_element_sprite;
    sfText *greeting_text;
    sfSprite *money_sprite;
    char *quantity_money_str;
    sfText *quantity_money;
} shop_t;

typedef enum item_type {
    NOTHING = 0,
    TEST
} item_type;

typedef struct image_s {
    sfSprite *sprite;
    sfVector2f pos;
} image_t;


typedef struct inventory_items_s {
    item_type slot1;
    item_type slot2;
    item_type slot3;
    item_type slot4;
    item_type slot5;
    item_type slot6;
    item_type slot7;
    item_type slot8;
    item_type slot9;
    item_type slot10;
    item_type slot11;
    item_type slot12;
    item_type slot13;
    item_type slot14;
    item_type slot15;
    item_type slot16;
    item_type slot17;
    item_type slot18;
    item_type slot19;
    item_type slot20;
    item_type slot21;
    item_type slot22;
    item_type slot23;
    item_type slot24;
    item_type sword_slot;
    item_type amulet_slot;
} inventory_items_t;

typedef struct save_s {
    sfVector2f pos_player;
    scene_type scene;
    stats_t stats;
    inventory_items_t inventory_items;
    int quest_index;
} save_t;

typedef struct text_s {
    char *string;
    char *id;
    sfVector2f pos;
    sfText *text;
} text_t;

typedef struct quests_s {
    char **quests;
    sfText *text;
    int index;
    sfBool display_text;
    sfBool display_text2;
    sfBool display_text3;
    int counter;
} quests_t;

typedef struct ui_s {
    image_t *quest_panel;
    image_t *display_health;
    text_t *hp_text;
} ui_t;

typedef struct game_s {
    my_window *win;
    my_textures_list *textures_list;
    scene_t *current_scene;
    scene_t *previous_scene;
    player_t *player;
    sfFont *dialog_font;
    sfColor filter_color;
    my_dialogbox *dialog;
    int anti_spam_keyboard;
    int clock_delay;
    double main_menu_move_speed;
    object_t *inventory_object;
    scene_type inventory_previous_scene;
    scene_type old_scene_type;
    sfBool already_saved;
    sounds_t *sounds;
    int fullscreen;
    sfVideoMode current_mode;
    char *window_name;
    sfWindowStyle window_style;
    quests_t *quests;
    maze_object_t *maze_object;
    sfVector2f *coord_pos_in_scene;
    sfBool have_to_reset_view;
    sfFont *main_font;
    sfBool end;
    ui_t *ui;
    int pick_up_mode_settings;
    int pick_up_index;
    sfKeyCode *keys;
} game_t;

#endif /* !STRUCT_MY_RPG_H_ */
