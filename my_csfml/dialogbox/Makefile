##
## EPITECH PROJECT, 2023
## B-MUL-200-STG-2-1-myrpg-florent.guittre
## File description:
## Makefile
##

SRC	=	dialogbox.c \
		dialog_gui.c \
		text_lines.c \
		waiting_triangle.c \
		dialog_mode.c \
		dialog_utils.c \
		read_line.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy-dialogbox.a

all: $(NAME)

CFLAGS	=	-g

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
