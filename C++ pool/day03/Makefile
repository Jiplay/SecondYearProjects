##
## EPITECH PROJECT, 2019
## ex00
## File description:
## Makefile
##

SRC	=	string.c	\
	string1.c	\
	string2.c	\
	string3.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libstring.a

CFLAGS	=  -I./include/ -std=gnu11 -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc libstring.a $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all