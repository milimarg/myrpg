/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** struct
*/

#ifndef STRUCT_SCENES_H_
    #define STRUCT_SCENES_H_
    #include "../my_rpg/my_rpg.h"

    #define SCENE_TYPE_NB 20

static sfVector2f SCENE_COORD_BASE_POS[] = {
    {1000, 700},
    {680, 850},
    {0, 0},
    {0, 0},
    {370, 420},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {1645, 1090},
    {0, 0},
    {0, 0},
    {0, 0}
};

typedef enum scene_type {
    MAIN_MENU = 0,
    MAIN_MAP,
    SETTINGS,
    CASTLE,
    CAVE,
    INVENTORY,
    JAIL,
    MAGIC_TOWER,
    MAZE,
    PAUSE,
    SHOP,
    TAVERN,
    DEATH,
    START_CINEMATIC,
    MAZE3D,
    MAIN_MAP_NIGHT,
    JEWEL_ROOM,
    THRONE_ROOM,
    BLACKSMITH,
    END
} scene_type;

static char *SCENE_TYPE_ID[] = {
    "main_menu",
    "main_map",
    "settings",
    "castle",
    "cave",
    "inventory",
    "jail",
    "magic_tower",
    "maze",
    "pause",
    "shop",
    "tavern",
    "death",
    "start_cinematic",
    "maze3d",
    "main_map_night",
    "jewel_room",
    "throne_room",
    "blacksmith",
    "end"
};

typedef struct scene_s {
    linked_list_object_t *object_list;
    scene_type type;
    char *id;
    sfBool can_player_move;
} scene_t;

#endif /* !STRUCT_SCENES_H_ */
