##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC_DIR=	src/
ENC_DIR=	encapsulation/

SRC=		$(SRC_DIR)main.cpp			\
			$(SRC_DIR)menu/menu.cpp	\
			$(SRC_DIR)game/gamecore.cpp	\
			$(SRC_DIR)game/gamebox.cpp	\
			$(SRC_DIR)game/gamebomba.cpp	\
			$(SRC_DIR)game/bombaInterraction.cpp	\
			$(SRC_DIR)game/borderWall.cpp	\
			$(SRC_DIR)game/destructibleWall.cpp	\
			$(SRC_DIR)game/player.cpp	\
			${SRC_DIR}map/proceduralMap.cpp	\
			${SRC_DIR}error/error.cpp	\
			Include/$(ENC_DIR)MyAudioE.cpp	\
			Include/$(ENC_DIR)MyCoreE.cpp	\
			Include/$(ENC_DIR)MyKeyE.cpp	\
			Include/$(ENC_DIR)MyModelsE.cpp	\
			Include/$(ENC_DIR)MyShapesE.cpp	\
			Include/$(ENC_DIR)MyTextureE.cpp	\
			Include/$(ENC_DIR)MyTextE.cpp	\

OBJ=		$(SRC:.cpp=.o)

NAME=		bomberman

CXXFLAGS=	-std=c++17

# CPPFLAGS=	-I Include/

all: 		$(NAME)

$(NAME): 	$(OBJ) 
			@echo "🚧 Building..."
			$(CXX) -o $(NAME) $(OBJ) -lraylib

run: clean all
		clear
		@echo "🚀 Executing..."
		./$(NAME)

valgrind: clean all
		clear
		@echo "🚀 Executing with valgrind..."
		valgrind --track-origins=yes ./$(NAME)

clean:
			@echo "🧹 Clearing..."
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all fclean clean re
