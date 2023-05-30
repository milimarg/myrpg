##
## EPITECH PROJECT, 2023
## doom
## File description:
## Makefile
##

SRC	=	src/lib/my_str_to_word_array_extra.c \
        src/lib/lib.c \
        src/lib/utils.c \
		src/draw/draw.c \
		src/draw/draw_wall.c \
		src/draw/points.c \
		src/move/move_player.c \
		src/move/move_player_body.c \
		src/move/move_player_view.c \
		src/move/move_strafe.c \
		src/world_handler.c \
		src/reload_world.c \
		src/convert_dante_to_config.c \
		src/walls.c \
		src/parser.c \
		src/sectors.c	\
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy-idt1.a

CFLAGS	=	-g -lm

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

OPENGL	=	-lGL -lGLU

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re



#SRC	=	src/lib/my_str_to_word_array_extra.c \
#        src/lib/lib.c \
#        src/lib/utils.c \
#		src/draw/draw.c \
#		src/draw/draw_wall.c \
#		src/draw/points.c \
#		src/move/move_player.c \
#		src/move/move_player_body.c \
#		src/move/move_player_view.c \
#		src/move/move_strafe.c \
#		src/world_handler.c \
#		src/reload_world.c \
#		src/convert_dante_to_config.c \
#		src/walls.c \
#		src/parser.c \
#		src/sectors.c	\
#		src/main.c
#
#OBJ	=	$(SRC:.c=.o)
#
## NAME	=	libmy-idt1.a
#NAME	=	nomdebinaire
#
#CFLAGS	=	-g -lm
#
#CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio
#
#OPENGL	=	-lGL -lGLU
#
#all: $(NAME)
#
#$(NAME): $(OBJ)
#	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CSFML) $(OPENGL)
## ar rc $(NAME) $(OBJ)
#
#clean:
#	rm -f $(OBJ)
#
#fclean: clean
#	rm -f $(NAME)
#
#re: fclean all
#
#.PHONY: all clean fclean re
