/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** parsing_npc
*/

#include "../../include/my_rpg/my_rpg.h"

static int size_word_array(char **tab)
{
    int len = 0;

    for (; tab[len]; len++);
    return (len);
}

int parsing_npc_ext(game_t *game, char **tab_arg, char *filepath, npc_t *npc)
{
    npc->id = tab_arg[1];
    npc->entity = spawn_entity(game->textures_list, tab_arg[5], 0);
    set_spawnpoint(npc->entity, &(sfVector2f){my_getnbr(tab_arg[2]),
    my_getnbr(tab_arg[3])}, 0);
    npc->talking_sprite = sfSprite_create();
    sfSprite_setTexture(npc->talking_sprite,
    find_texture_in_list(game->textures_list, tab_arg[6])->texture, sfTrue);
    npc->dialog_index = 0;
    add_to_object_list(game, init_object(npc, NPC, tab_arg[1]), NPC);
    return (0);
}

void parsing_npc_two(char ***tab_tab, char *path_gene, int len_path_gene,
npc_t *npc)
{
    for (int i = 0; tab_tab[0][i] != NULL; i++)
        free(tab_tab[0][i]);
    free(tab_tab[0]);
    tab_tab[0] = my_str_to_word_array_specified(tab_tab[2][4], ':');
    tab_tab[1] = malloc(sizeof(char *)
    * (size_word_array(tab_tab[0]) + 1));
    for_one_parsing(tab_tab[0], tab_tab[1], path_gene, len_path_gene);
    npc->dialog_path = tab_tab[1];
}

int parsing_npc(game_t *game, char **tab_arg, char *filepath)
{
    npc_t *npc = malloc(sizeof(npc_t));
    char **dialog_path = NULL;
    char *path_gene = NULL;
    char **temp_filepath_cut = my_str_to_word_array_specified(filepath, '/');
    int len = 0;
    int len_path_gene = 0;

    first_function(&path_gene, temp_filepath_cut, &len_path_gene, tab_arg);
    for (; tab_arg[len] != NULL; len++);
    if (len != 7) {
        write(2, filepath, my_strlen(filepath));
        write(2, ": wrong file\n", 13);
        return (84);
    }
    parsing_npc_two((char **[3]){temp_filepath_cut, dialog_path, tab_arg},
    path_gene, len_path_gene, npc);
    if (parsing_npc_ext(game, tab_arg, filepath, npc) != 0)
        return (84);
    return (0);
}
