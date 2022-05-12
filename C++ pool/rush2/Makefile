##
## File description:
## Makefile
##


SRC_DIR=	src/

SRC=		$(SRC_DIR)*.cpp			\
			main.cpp	\

OBJ=		$(SRC:.cpp=.o)

NAME=		rush_2

CXXFLAGS=	-std=c++17

CPPFLAGS=	-I include/

all: 		$(NAME)

$(NAME): 	$(OBJ) 
			@echo "🚧 Building..."
			$(CXX) -o $(NAME) $(OBJ)

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
