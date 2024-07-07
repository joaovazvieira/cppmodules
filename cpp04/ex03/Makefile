CC		=	g++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98 -g
# CFLAGS	+= -fsanitize=address

SRCS	=	main.cpp\
			Ice.cpp\
			Cure.cpp\
			AMateria.cpp\
			Character.cpp\
			MateriaSource.cpp\

INC		=	AMateria.hpp\
			Ice.hpp\
			Cure.hpp\
			Character.hpp\
			MateriaSource.hpp\
			ICharacter.hpp\
			IMateriaSource.hpp\

OBJ		=	$(SRCS:%.cpp=$(OBJ_DIR)/%.o)
OBJ_DIR	=	obj
NAME	=	AMateria

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