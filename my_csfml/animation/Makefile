##
## EPITECH PROJECT, 2023
## my_csfml_container
## File description:
## Makefile
##

SRC	=	animation.c	\
		destroy.c \
		texture.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy-animation.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
