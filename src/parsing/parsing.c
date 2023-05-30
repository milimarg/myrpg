/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** parsing
*/

#include "../../include/my_rpg/my_rpg.h"

int parsing_map(game_t *game, char **tab_arg, char *filepath);
int parsing_button(game_t *game, char **tab_arg, char *filepath);
int parsing_npc(game_t *game, char **tab_arg, char *filepath);
int parsing_tp(game_t *game, char **tab_arg, char *filepath);

void parsing_files_loop(game_t *game, char *string, char *filepath)
{
    char **parsed_string = NULL;
    int tab_index = 0;
    char **cut_string = my_str_to_word_array_specified(string, '\n');

    for (int i = 0; cut_string[i]; i++) {
        if (my_strlen(cut_string[0]) <= 1)
            continue;
        if (cut_string[i][0] == '/' && cut_string[i][1] == '/')
            continue;
        parsed_string = my_str_to_word_array(cut_string[i]);
        tab_index = my_getnbr(parsed_string[0]);
        if (tab_index >= PARSING_TAB_SIZE) {
            write(2, "wrong index\n\n", 13);
            continue;
        }
        if (PARSING_TAB[tab_index](game, parsed_string, filepath) != 0)
            return;
    }
}

int parsing_files(game_t *game, char *dir_path_name)
{
    int size_filepath = my_strlen("./data") + my_strlen(dir_path_name) +
    my_strlen("/objects/objects") + 1;
    char *filepath = malloc(sizeof(char) * (size_filepath));
    for (int i = 0; i < size_filepath; i++)
        filepath[i] = '\0';
    filepath = my_strcat(my_strcat(my_strcat(filepath, "./data"),
    dir_path_name), "/objects/objects\0");
    int fd = open(filepath, O_RDONLY);
    struct stat st = {0};
    char *string = NULL;
    if (fd == -1) {
        write(2, "file not found\n", 15);
        return (84);
    }
    stat(filepath, &st);
    string = malloc(sizeof(char) * (st.st_size + 1));
    read(fd, string, st.st_size);
    string[st.st_size] = '\0';
    parsing_files_loop(game, string, filepath);
    return (0);
}
