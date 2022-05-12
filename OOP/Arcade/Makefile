##
## Makefile for B-OOP-400-PAR-4-1-arcade-ibrahim.zafar
##
## Made by julien.garsia
## Login   <julien.garsia>
##
## Started on  Tue Mar 16 11:35:59 AM 2021 julien.garsia
## Last update Sat Apr 16 9:41:04 AM 2021 julien.garsia
##

SRC_DIR=	src/

SRC=		main.cpp			\
			$(SRC_DIR)exceptions/error.cpp 		\
			$(SRC_DIR)dlopen_encapsulated.cpp 		\
			$(SRC_DIR)core/main_core.cpp

OBJ=		$(SRC:.cpp=.o)

NAME=		arcade

CXXFLAGS=	-std=c++17

CPPFLAGS=	-I include/

all: 		core graphicals games

core: 	$(NAME)

graphicals:
	make re -C ./lib

games:
	make re -C ./lib/games

$(NAME): 	$(OBJ) 
			@echo "🚧 Building..."
			$(CXX) -o $(NAME) $(OBJ) -ldl

clean:
			@echo "🧹 Clearing..."
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all fclean clean re graphicals games core