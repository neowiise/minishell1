##
## EPITECH PROJECT, 2023
## minishell
## File description:
## Makefile
##

NAME	=	mysh

SRC		=	./src/main.c	\
			./src/get_input.c	\
			./src/init_linked_list.c	\
			./src/get_content.c			\
			./src/handle_excve.c		\
			./src/env_set_unset.c		\
			./src/handle_cd.c			\
			./src/get_command_path.c	\
			./lib/my_strcmp.c			\
			./lib/my_strlen.c			\
			./lib/my_strdup.c			\
			./lib/my_str_to_word_array.c	\
			./lib/str_to2.c					\
			./lib/my_putstr.c				\
			./lib/my_putchar.c				\
			./lib/my_strcat.c				\
			./src/check_command.c			\
			./lib/my_strncmp.c				\
			./lib/handlings.c				\
			./lib/mini_printf.c				\
			./lib/my_put_nbr.c				\
			./src/error_env.c				\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wextra	-Wall	 -ggdb

all:	$(OBJ)
		gcc	$(CFLAGS)	-o $(NAME) $(OBJ)
		make clean

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all


.PHONY:	all clean fclean re
