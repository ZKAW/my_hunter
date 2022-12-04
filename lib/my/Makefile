##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## build library
##

SRC = my_putchar.c \
	my_putstr.c \
	my_revstr.c \
	my_strlen.c \
	my_intlen.c \
	my_itoa.c \
	my_getnbr.c \

OBJ = $(SRC:.c=.o)
NAME = libmy.a
NAME_H = my.h

all: $(NAME)

.SILENT:
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../$(NAME)
	mkdir -p ../../include
	cp $(NAME_H) ../../include/$(NAME_H)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ)
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../$(NAME)

re: fclean all
