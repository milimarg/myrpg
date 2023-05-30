/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** parsing_tp
*/

#include "../../include/my_rpg/my_rpg.h"

tp_t *add_tp(sfVector2i *start_end_spawn_point,
scene_type *trigger_scene_and_scene_type_switch, int orientation)
{
    tp_t *tp = malloc(sizeof(tp_t));

    tp->start = start_end_spawn_point[0];
    tp->end = start_end_spawn_point[1];
    tp->spawn_point = start_end_spawn_point[2];
    tp->trigger_scene = trigger_scene_and_scene_type_switch[0];
    tp->scene_type_switch = trigger_scene_and_scene_type_switch[1];
    tp->orientation = orientation;
    return (tp);
}

int find_enum_index_from_id(char *id)
{
    for (int i = 0; i < SCENE_TYPE_NB; i++) {
        if (my_strcmp(id, SCENE_TYPE_ID[i]) == 0)
            return (i);
    }
    return (-1);
}

int parsing_tp_ext(game_t *game, char **tab_arg, char *filepath)
{
    scene_type trigger_scene = 0;
    scene_type scene_type_switch = 0;
    tp_t *tp = NULL;

    trigger_scene = find_enum_index_from_id(tab_arg[8]);
    scene_type_switch = find_enum_index_from_id(tab_arg[9]);
    if (trigger_scene == -1 || scene_type_switch == -1) {
        write(2, filepath, my_strlen(filepath));
        write(1, ": invalid values\n", 17);
        return (84);
    }
    tp = add_tp((sfVector2i [3]){
        (sfVector2i){my_getnbr(tab_arg[2]), my_getnbr(tab_arg[4])},
        (sfVector2i){my_getnbr(tab_arg[3]), my_getnbr(tab_arg[5])},
        (sfVector2i){my_getnbr(tab_arg[6]), my_getnbr(tab_arg[7])}
    }, (scene_type [2]){trigger_scene, scene_type_switch},
    my_getnbr(tab_arg[10]));
    add_to_object_list(game, init_object(tp, TP, tab_arg[1]), TP);
    return (0);
}

int parsing_tp(game_t *game, char **tab_arg, char *filepath)
{
    int len = 0;
    tp_t *tp = NULL;
    scene_type trigger_scene = 0;
    scene_type scene_type_switch = 0;

    for (; tab_arg[len] != NULL; len++);
    if (len != 11) {
        write(2, filepath, my_strlen(filepath));
        write(2, ": wrong file\n", 13);
        return (84);
    }
    if (parsing_tp_ext(game, tab_arg, filepath) != 0)
        return (84);
    return (0);
}
