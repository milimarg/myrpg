/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** parsing_npc_two
*/

#include "../../include/my_rpg/my_rpg.h"

void for_one_parsing(char **temp_filepath_cut, char **dialog_path,
char *path_gene, int len_path_gene)
{
    for (int i = 0; temp_filepath_cut[i] != NULL; i++) {
        dialog_path[i] = malloc(sizeof(char)
        * (len_path_gene + my_strlen(temp_filepath_cut[i]) + 1));
        for (int j = 0; j < len_path_gene
        + my_strlen(temp_filepath_cut[i]) + 1; j++)
            dialog_path[i][j] = '\0';
        dialog_path[i] = my_strcat(my_strcat(dialog_path[i], path_gene),
        temp_filepath_cut[i]);
    }
}

void first_function(char **path_gene, char ** temp_filepath_cut,
int *len_path_gene, char **tab_arg)
{
    (*path_gene) = malloc(sizeof(char) * (16 +
    my_strlen(temp_filepath_cut[3])));
    for (int i = 0; i < 16 + my_strlen(temp_filepath_cut[3]); i++)
        (*path_gene)[i] = '\0';
    (*path_gene) = my_strcat(my_strcat(my_strcat((*path_gene),
    "./data/scenes/"),
    temp_filepath_cut[3]), "/");
    (*len_path_gene) = my_strlen((*path_gene));
}
