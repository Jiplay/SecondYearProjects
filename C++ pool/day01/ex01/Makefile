##
## Makefile for Pool  in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/Pool 
##
## Made by julien.garsia
## Login   <julien.garsia>
##
## Started on  Wed Jan 6 9:18:08 AM 2021 julien.garsia
## Last update Thu Jan 6 11:09:19 AM 2021 julien.garsia
##

SRC	=	main.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	menger

CFLAGS	=  -I./include/ -std=gnu11 -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
