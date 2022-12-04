##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## build library
##

SRC = my_pow.c \
	my_sqrt.c \
	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_revstr.c \
	my_strcpy.c \
	my_strncpy.c \
	my_strlen.c \
	my_putstr_err.c \
	my_intlen.c \
	my_putnbr_base.c \
	my_itoa.c \
	my_itoa_base.c \
	count_nbr_digits.c \
	my_round.c \
	my_longlen.c \
	my_put_float.c \
	my_put_hexa.c \
	my_doublelen.c \
	my_strcmp.c \
	my_strdup.c \
	my_strlowercase.c \
	my_strcat.c \
	my_tablen.c \
	my_getnbr.c \
	reverse_tab.c \
	my_strstr.c \
	my_chartolower.c \

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
