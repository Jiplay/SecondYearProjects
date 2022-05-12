##
## File description:
## Makefile
##


SRC_DIR=	src/

SRC=		$(SRC_DIR)main.cpp	\
			$(SRC_DIR)parser/parser.cpp	\
			$(SRC_DIR)parser/create.cpp \
			$(SRC_DIR)compo/pin.cpp	\
			$(SRC_DIR)compo/c4001.cpp	\
			$(SRC_DIR)compo/c4011.cpp	\
			$(SRC_DIR)compo/c4030.cpp	\
			$(SRC_DIR)compo/c4071.cpp	\
			$(SRC_DIR)compo/c4081.cpp	\
			$(SRC_DIR)compo/output.cpp	\
			$(SRC_DIR)compo/input.cpp	\
			$(SRC_DIR)compo/true.cpp	\
			$(SRC_DIR)compo/false.cpp	\
			$(SRC_DIR)CLI/cli.cpp	\
			$(SRC_DIR)exceptions/errors.cpp


OBJ=		$(SRC:.cpp=.o)

NAME=		nanotekspice

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
