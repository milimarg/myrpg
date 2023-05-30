##
## EPITECH PROJECT, 2023
## my_csfml_container
## File description:
## Makefile
##

SRC	=	window.c	\
		background.c	\
		destroy.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy-window.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
