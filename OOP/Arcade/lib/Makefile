##
## Makefile for B-OOP-400-PAR-4-1-arcade-ibrahim.zafar
##
## Made by julien.garsia
## Login   <julien.garsia>
##
## Started on  Mon Mar 15 12:30:56 PM 2021 julien.garsia
## Last update Sun Apr 10 5:39:45 PM 2021 julien.garsia
##

## EVERYTHING ABOUT SLD2

NAME_SDL 		=./SLD2/arcade_sdl2.so
SRC_SDL 		= ./SLD2/SDL2.cpp
OBJS_SDL 		= $(SRC_SDL:.cpp=.o)
SDL_FLAGS = `sdl2-config --cflags --libs`

## EVERYTHING ABOUT SFML

NAME_SFML		=./SFML/arcade_sfml.so
SRC_SFML		= ./SFML/SFML.cpp
OBJS_SFML 		= $(SRC_SFML:.cpp=.o)
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

## EVERYTHING ABOUT NCURSES

NAME_NCURSES		=./NCURSES/arcade_ncurses.so
SRC_NCURSES		= ./NCURSES/ncurses.cpp
OBJS_NCURSES 		= $(SRC_NCURSES:.cpp=.o)
NCURSES_FLAGS = -lncurses

GPP = g++

CFLAGS	= -W -Wall -Wextra -pedantic -std=c++17 -fPIC

RM		= rm -rf

all:	$(NAME_SFML) $(NAME_SDL) $(NAME_NCURSES) $(NAME_NIBBLER)
		mv NCURSES/*.so .
		mv SFML/*.so .
		mv SLD2/*.so .

$(NAME_SDL):
	$(GPP) $(CFLAGS) -shared $(SRC_SDL) -o $(NAME_SDL) $(SDL_FLAGS) -lSDL2 -lSDL2_ttf

$(NAME_SFML):
	$(GPP) $(CFLAGS) -shared $(SRC_SFML) -o $(NAME_SFML) $(SFML_FLAGS)

$(NAME_NCURSES):
	$(GPP) $(CFLAGS) -shared $(SRC_NCURSES) -o $(NAME_NCURSES) $(NCURSES_FLAGS)

clean: 
	@echo "🧹 Clearing..."
	$(RM) *.o

fclean:		clean
		$(RM) $(NAME_SDL)
		$(RM) $(NAME_SFML)
		$(RM) $(NAME_NCURSES)


re:		fclean all

.PHONY:		all clean fclean re
