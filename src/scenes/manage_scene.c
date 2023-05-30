/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene
*/

#include "../../include/my_rpg/my_rpg.h"

void switch_scene_ext(game_t *game, scene_type type, char *id)
{
    scene_t *temp = NULL;

    if (game->previous_scene->type == type) {
        temp = game->previous_scene;
        game->previous_scene = game->current_scene;
        game->current_scene = temp;
        INIT_SCENE_POINTER_ACTION[type](game);
    } else {
        game->previous_scene = game->current_scene;
        game->current_scene = NULL;
        init_scene(game, id, type);
    }
}

void switch_scene(game_t *game, scene_type type, char *id)
{
    if (game->current_scene != NULL) {
        game->old_scene_type = game->current_scene->type;
    }
    if (game->previous_scene == NULL) {
        game->previous_scene = game->current_scene;
        game->current_scene = NULL;
        init_scene(game, id, type);
        return;
    }
    switch_scene_ext(game, type, id);
}

void destroy_scene(game_t *game)
{
    for (linked_list_object_t *list = game->current_scene->object_list;
    list != NULL; list = list->next) {
        list->object->destroy(list->object->struct_type, game);
    }
    free(game->current_scene);
}

void init_scene(game_t *game, char *id, scene_type type)
{
    int init_path_size = my_strlen("/scenes/") + my_strlen(id) + 1;
    char *init_path = malloc(sizeof(char) * (init_path_size));

    for (int i = 0; i < init_path_size; i++)
        init_path[i] = '\0';
    init_path = my_strcat(my_strcat(init_path, "/scenes/"), id);
    game->current_scene = malloc(sizeof(scene_t));
    game->current_scene->object_list = NULL;
    game->current_scene->type = type;
    game->current_scene->id = SCENE_TYPE_ID[type];
    parsing_files(game, init_path);
    INIT_SCENE_POINTER_ACTION[type](game);
    INIT_SCENE_POINTER[type](game);
}

    // faire des reset de la view dans toutes les fonctions
    //-> set la view dans toutes celles qui l'utilisent
    //
    // IMPORTANT -> gestion des scènes quand l'init_scene plus en debug
    // if (game->current_scene != NULL) {
    //     if (game->current_scene->type != INVENTORY
    //         && game->current_scene->type != PAUSE) {
    //         game->old_scene_type = game->current_scene->type;
    //     }
    //     free (game->current_scene);
    // } else {
    // }
