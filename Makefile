##
## EPITECH PROJECT, 2022
## bsmyhunter
## File description:
## Makefile
##

NAME = my_hunter
CC	= gcc
SRC	= src/main.c \
	src/my_hunter.c \
	src/helpers/window.c \
	src/helpers/events.c \
	src/helpers/sprites.c \
	src/helpers/linked.c \
	src/helpers/clock.c \
	src/helpers/texture.c \

OBJ	= $(SRC:.c=.o)

LIBFLAG	= -Wall -Wextra -lcsfml-graphics -lcsfml-window \
		-lcsfml-system -lcsfml-audio

all: $(NAME)
$(NAME):
	$(CC) -o $(NAME) $(SRC) $(LIBFLAG) -g

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

cstyle:
	make fclean
	cstyle
