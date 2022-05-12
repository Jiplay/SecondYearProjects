##
## File description:
## Makefile
##


SRC_DIR=	src/

SRC=		main.cpp 	\
			src/Core/main_core.cpp	\
			src/Ncurses/main_ncurse.cpp	\
			src/SFML/main_sfml.cpp	\


OBJ=		$(SRC:.cpp=.o)

NAME=		MyGKrellm

CXXFLAGS=	-std=c++17
CPPFLAGS=	-I include/

all: 		$(NAME)

$(NAME): 	$(OBJ) 
			@echo "🚧 Building..."
			$(CXX) -o $(NAME) $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system -lncurses

run: clean all
		clear
		@echo "🚀 Executing..."
		./$(NAME)

clean:
			@echo "🧹 Clearing..."
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all fclean clean re
