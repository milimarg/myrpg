##
## EPITECH PROJECT, 2023
## my_csfml
## File description:
## Makefile
##

SRC	=	button.c \
		button_utils.c \
		dropdowns.c \
		dropdown_utils.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy-button.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
