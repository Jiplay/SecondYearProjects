##
## EPITECH PROJECT
## 
## File description:
## Makefile
##


SRC_DIR=	src/

SRC=		$(SRC_DIR)main.cpp			\
			$(SRC_DIR)kitchen.cpp 		\
			$(SRC_DIR)else.cpp 			\
			$(SRC_DIR)pizza.cpp 		\
			$(SRC_DIR)parser.cpp		\
			$(SRC_DIR)baking.cpp		\
			$(SRC_DIR)pipe.cpp			\
			$(SRC_DIR)mutex.cpp			\
			$(SRC_DIR)process.cpp		\
			$(SRC_DIR)error.cpp			\
			$(SRC_DIR)thread.cpp		\
			$(SRC_DIR)cond_var.cpp		\
			$(SRC_DIR)my_thread_pool.cpp\
			$(SRC_DIR)Logger.cpp		\

OBJ=		$(SRC:.cpp=.o)

NAME=		plazza

CXXFLAGS=	-std=c++17

CPPFLAGS=	-I include/

all: 		$(NAME)

$(NAME): 	$(OBJ) 
			@echo "🚧 Building..."
			$(CXX) -o $(NAME) $(OBJ) -pthread

run: clean all
		clear
		@echo "🚀 Executing..."
		./$(NAME) 1 2 2000

valgrind: clean all
		clear
		@echo "🚀 Executing with valgrind..."
		valgrind --track-origins=yes ./$(NAME) 1 2 2000

clean:
			@echo "🧹 Clearing..."
			$(RM) $(OBJ)
			$(RM) logs/*.log

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all fclean clean re
