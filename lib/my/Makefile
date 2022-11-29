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
	my_itoa_base.c \
	count_nbr_digits.c \
	my_round.c \
	my_longlen.c \
	my_put_double.c \
	my_put_float.c \
	my_put_hexa.c \
	my_doublelen.c \
	my_strcmp.c \
	my_strdup.c \
	my_strlowercase.c \
	my_strcat.c \
	my_tablen.c \
	reverse_tab.c \
	my_strstr.c \
	my_chartolower.c \
	my_printf/workers/flags/base.c \
	my_printf/workers/flags/string.c \
	my_printf/workers/flags/unsigned.c \
	my_printf/workers/flags/double.c \
	my_printf/workers/flags/other.c \
	my_printf/workers/subflags/format.c \
	my_printf/workers/parser/handler.c \
	my_printf/workers/parser/scrapper.c \
	my_printf/helpers/is_nbr_positive.c \
	my_printf/helpers/base_prefix.c \
	my_printf/helpers/errors.c \
	my_printf/helpers/get_length.c \
	my_printf/helpers/get_length2.c \
	my_printf/my_printf.c

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
	cp my_printf/include/my_printf.h ../../include/my_printf.h

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ)
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../$(NAME)

re: fclean all
