##
## EPITECH PROJECT, 2023
## my_csfml
## File description:
## Makefile
##

SRC	=	container.c	\
		items.c \
		items_utils.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy-container.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
