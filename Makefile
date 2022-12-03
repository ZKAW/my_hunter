##
## EPITECH PROJECT, 2022
## my_hunter
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
	src/helpers/display.c \
	src/helpers/game.c \
	src/helpers/lifebar.c \
	src/helpers/utils.c \
	src/helpers/scenes.c \
	src/helpers/audio.c \

OBJ	= $(SRC:.c=.o)

LIBFLAG	= -Wall -Wextra -lcsfml-graphics -lcsfml-window \
		-lcsfml-system -lcsfml-audio -lmy -L./lib/my

all: $(NAME)
$(NAME):
	make -C lib/my
	$(CC) -o $(NAME) $(SRC) $(LIBFLAG) -g

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C lib/my
	rm -f $(NAME)

re: fclean all

cstyle:
	make fclean
	cstyle

start:
	make re
	./my_hunter
