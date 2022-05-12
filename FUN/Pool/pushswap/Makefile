##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC =	main.hs

NAME = 	pushswap_checker

all: $(NAME)

$(NAME):
		ghc $(SRC) -o $(NAME)

clean:
		rm -f *.hi
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: 	fclean all

.PHONY: all clean fclean re