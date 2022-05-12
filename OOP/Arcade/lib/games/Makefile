##
## Makefile for B-OOP-400-PAR-4-1-arcade-ibrahim.zafar
##
## Made by julien.garsia
## Login   <julien.garsia>
##
## Started on  Mon Mar 15 12:30:56 PM 2021 julien.garsia
## Last update Sun Apr 10 5:41:20 PM 2021 julien.garsia
##

## GAME NIBBLER NCURSES

NAME_NIBBLER		=./nibbler/arcade_nibbler.so
SRC_NIBBLER		= ./nibbler/nibbler.cpp \
				../../src/dlopen_encapsulated.cpp	\
				# ../NCURSES/ncurses.cpp

OBJS_NIBBLER 		= $(SRC_NIBBLER:.cpp=.o)
NIBBLER_FLAGS = -lncurses

NAME_PACMAN		=./pacman/arcade_pacman.so
SRC_PACMAN		= ./pacman/pacman.cpp

OBJS_PACMAN 		= $(SRC_PACMAN:.cpp=.o)
PACMAN_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system


GPP = g++

CFLAGS	= -W -Wall -Wextra -pedantic -std=c++17 -fPIC

RM		= rm -rf

all:	$(NAME_NIBBLER) $(NAME_PACMAN)
		mv nibbler/*.so ..
		mv pacman/*.so ..

$(NAME_NIBBLER):
	$(GPP) $(CFLAGS) -shared $(SRC_NIBBLER) -o $(NAME_NIBBLER) $(NIBBLER_FLAGS)

$(NAME_PACMAN):
	$(GPP) $(CFLAGS) -shared $(SRC_PACMAN) -o $(NAME_PACMAN) $(PACMAN_FLAGS)


clean: 
	@echo "🧹 Clearing..."
	$(RM) *.o

fclean:		clean
		$(RM) $(NAME_NIBBLER)
		$(RM) $(NAME_PACMAN)


re:		fclean all

.PHONY:		all clean fclean re
