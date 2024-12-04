CC		=	g++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98 -g
CFLAGS	+= -fsanitize=address

SRCS	=	main.cpp\
			Cat.cpp\
			Dog.cpp\
			Brain.cpp\
			AAnimal.cpp\
			WrongCat.cpp\
			WrongAnimal.cpp\

INC		=	AAnimal.hpp Cat.hpp Dog.hpp WrongCat.hpp WrongAnimal.hpp Brain.hpp
OBJ		=	$(SRCS:%.cpp=$(OBJ_DIR)/%.o)
OBJ_DIR	=	obj
NAME	=	Animal

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compiling
	@$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
# @echo Compiling
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@echo "Removing $(OBJ_DIR)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Removing $(NAME)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re