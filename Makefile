##
## EPITECH PROJECT, 2023
## B-MUL-200-STG-2-1-myrpg-florent.guittre
## File description:
## Makefile
##

SRC	=	src/main.c	\
		my_csfml/lib.c \
		src/game_loop/draw/draw.c	\
		src/game_loop/draw/set_player_position.c	\
		src/game_loop/draw/draw_two.c	\
		src/game_loop/event/event.c	\
		src/game_loop/event/move_map_main_menu.c	\
		src/game_loop/loop/game_loop.c	\
		src/game_loop/loop/initialisation/init_game_loop.c	\
		src/game_loop/loop/initialisation/init_player.c	\
		src/game_loop/loop/initialisation/init_inventory.c	\
		src/game_loop/loop/initialisation/init_elems.c	\
		src/game_loop/loop/initialisation/init_quests.c	\
		src/game_loop/loop/ui_functions.c	\
		src/game_loop/loop/ui_functions_two.c	\
		src/game_loop/timer/timer.c	\
		src/game_loop/update/update.c \
		src/game_loop/update/update_mob_functions.c \
		src/game_loop/update/update_pick_up_settings.c \
		src/game_loop/update/update_tower.c \
		src/game_loop/update/take_flower.c \
		src/game_loop/update/update_castle.c \
		src/game_loop/update/move_player.c \
		src/game_loop/update/move_player_utils.c \
		src/game_loop/update/move_mob_in_tavern.c \
		src/lib/my_str_to_word_array.c	\
		src/lib/my_strcat.c	\
		src/lib/my_strcmp.c	\
		src/lib/my_strncmp.c \
		src/lib/my_get_nbr.c	\
		src/lib/screenshot.c	\
		src/lib/my_intlen.c \
		src/lib/my_int_to_str.c \
		src/mob/link_list_of_mob_move.c	\
		src/mob/init_move_mob.c	\
		src/mob/action_mob.c	\
		src/mob/collision_up_down_mob.c	\
		src/mob/collision_left_mob.c	\
		src/mob/collision_right_mob.c	\
		src/my_rpg/update_start_scene.c \
		src/object/object_functions/map_functions.c	\
		src/object/object_functions/tp_functions.c	\
		src/object/object_functions/tp_update.c	\
		src/object/object_functions/npc_functions.c	\
		src/object/object_functions/inventory_functions.c \
		src/object/object_functions/inventory_update.c \
		src/object/object_functions/pause_functions.c \
		src/object/object_functions/start_cinematic_functions.c	\
		src/object/object_functions/main_map_night_functions.c \
		src/object/object_functions/maze3d_functions.c \
		src/object/object_functions/mob_functions.c	\
		src/object/object_functions/image_functions.c	\
		src/object/object_functions/jewels_functions.c \
		src/object/object_functions/jewels_functions_update.c \
		src/object/object_functions/shop_functions.c	\
		src/object/object_functions/text_functions.c	\
		src/object/object_functions/entity_functions.c	\
		src/object/object_functions/throne_functions.c \
		src/object/object_functions/button_functions.c	\
		src/object/object_list.c	\
		src/object/add_to_object_list.c	\
		src/object/init_object.c	\
		src/object/inventory/inventory_utils.c	\
		src/parsing/parsing.c	\
		src/parsing/parsing_map.c	\
		src/parsing/parsing_button.c	\
		src/parsing/parsing_npc.c	\
		src/parsing/parsing_npc_two.c	\
		src/parsing/parsing_tp.c	\
		src/parsing/parsing_texture.c	\
		src/parsing/parsing_mob.c	\
		src/parsing/parsing_image.c	\
		src/parsing/parsing_text.c \
		src/player/update_xp.c \
		src/player/timer_attack_player.c \
		src/player/regeneration_player.c \
		src/player/action_player.c	\
		src/save/save.c \
		src/save/load.c \
		src/scenes/manage_scene.c	\
		src/scenes/main_menu/button_functions/button_kinds.c \
		src/scenes/main_menu/button_functions/title.c \
		src/scenes/pause/button_functions/button_kinds.c	\
		src/scenes/settings/button_functions/button_functions_music.c \
		src/scenes/settings/button_functions/button_functions_resolution.c \
		src/scenes/settings/button_functions/button_functions_screen.c \
		src/scenes/settings/button_functions/button_functions_sound.c \
		src/scenes/settings/button_functions/button_functions_keys_interact.c \
		src/scenes/settings/button_functions/button_functions_keys_move.c \
		src/scenes/shop/shop.c	\
		src/scenes/shop/add_item.c	\
		src/scenes/shop/display.c	\
		src/scenes/shop/give_item.c	\
		src/scenes/shop/greetings.c	\
		src/scenes/shop/move_item.c	\
		src/scenes/shop/set_rect.c	\
		src/scenes/settings/button_functions/button_back.c \
		src/scenes/castle/init_scene_action.c	\
        src/scenes/cave/init_scene_action.c	\
        src/scenes/death/init_scene_action.c	\
        src/scenes/end/init_scene_action.c	\
        src/scenes/inventory/init_scene_action.c	\
		src/scenes/inventory/button_functions/button_kinds.c	\
        src/scenes/jail/init_scene_action.c	\
        src/scenes/jewels_room/init_scene_action.c	\
        src/scenes/magic_tower/init_scene_action.c	\
        src/scenes/main_map/init_scene_action.c	\
        src/scenes/main_map_night/init_scene_action.c	\
        src/scenes/main_menu/init_scene_action.c	\
        src/scenes/maze/init_scene_action.c	\
        src/scenes/maze3d/init_scene_action.c	\
        src/scenes/pause/init_scene_action.c	\
        src/scenes/settings/init_scene_action.c	\
        src/scenes/shop/init_scene_action.c	\
        src/scenes/start_cinematic/init_scene_action.c	\
        src/scenes/tavern/init_scene_action.c	\
        src/scenes/throne_room/init_scene_action.c	\
        src/scenes/blacksmith/init_scene_action.c	\
		src/scenes/castle/init_scene.c	\
        src/scenes/cave/init_scene.c	\
        src/scenes/death/init_scene.c	\
        src/scenes/end/init_scene.c	\
        src/scenes/inventory/init_scene.c	\
        src/scenes/jail/init_scene.c	\
        src/scenes/jewels_room/init_scene.c	\
        src/scenes/magic_tower/init_scene.c	\
        src/scenes/main_map/init_scene.c	\
        src/scenes/main_map_night/init_scene.c	\
        src/scenes/main_menu/init_scene.c	\
        src/scenes/maze/init_scene.c	\
        src/scenes/maze3d/init_scene.c	\
        src/scenes/pause/init_scene.c	\
        src/scenes/settings/init_scene.c	\
        src/scenes/shop/init_scene.c	\
        src/scenes/start_cinematic/init_scene.c	\
        src/scenes/tavern/init_scene.c	\
        src/scenes/throne_room/init_scene.c	\
        src/scenes/blacksmith/init_scene.c	\

BUILD	=	build

OBJ	=	$(patsubst src/%.c, $(BUILD)/%.o, $(SRC))

# OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS	=	-lm

GLFLAGS	=	-lGL -lGLU

DEBUG	=	-g

COMP_DEBUG	=	-Wall -Wextra

LIB_CSFML	=	-L./my_csfml/animation -lmy-animation	\
				-L./my_csfml/button -lmy-button	\
				-L./my_csfml/container -lmy-container	\
				-L./my_csfml/entity -lmy-entity	\
				-L./my_csfml/window -lmy-window \
				-L./my_csfml/dialogbox -lmy-dialogbox

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

IDT1	=	-L./idt1/ -lmy-idt1

all: $(NAME)

$(NAME): $(OBJ)
	make re -C ./my_csfml/animation
	make re -C ./my_csfml/button
	make re -C ./my_csfml/container
	make re -C ./my_csfml/entity
	make re -C ./my_csfml/window
	make re -C ./my_csfml/dialogbox
	make re -C ./idt1/
	gcc $(OBJ) -o $(NAME) $(LIB_CSFML) $(IDT1) $(CSFML) $(GLFLAGS) $(CFLAGS)

# debug:	$(OBJ)
# 	make re -C ./my_csfml/animation
# 	make re -C ./my_csfml/button
# 	make re -C ./my_csfml/container
# 	make re -C ./my_csfml/entity
# 	make re -C ./my_csfml/window
# 	make re -C ./my_csfml/dialogbox
# 	gcc $(OBJ) -o $(NAME) $(LIB_CSFML) $(CSFML) $(CFLAGS) $(DEBUG)
# -> se baser sur le $(BUILD) et non le $(NAME)

$(BUILD)/%.o: src/%.c
	mkdir -p $(dir $@)
	gcc -c $< -o $@ $(DEBUG)
#	gcc $(CFLAGS) -c $< -o $@ $(DEBUG)

clean:
	rm -rf $(BUILD)
	make clean -C ./my_csfml/animation
	make clean -C ./my_csfml/button
	make clean -C ./my_csfml/container
	make clean -C ./my_csfml/entity
	make clean -C ./my_csfml/window
	make clean -C ./my_csfml/dialogbox
	make clean -C ./idt1

fclean: clean
	rm -f $(NAME)
	make fclean -C ./my_csfml/animation
	make fclean -C ./my_csfml/button
	make fclean -C ./my_csfml/container
	make fclean -C ./my_csfml/entity
	make fclean -C ./my_csfml/window
	make fclean -C ./my_csfml/dialogbox
	make fclean -C ./idt1

re: fclean all

.PHONY: all clean fclean re
