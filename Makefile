##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	src/my_cipher_define.c \
		src/my_cipher_deter.c \
		src/my_cipher_rev.c \
		src/my_cipher_reverse.c \
		src/my_cipher.c \
		src/my_get.c \
		src/my_put.c \
		src/my_report.c \
		src/my_utils.c \
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	103cipher

all:	$(NAME)

$(NAME):
	make -C tests
	gcc $(SRC) -Wall -Wextra -I include -o $(NAME) -g -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
