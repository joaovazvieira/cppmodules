CC 		= g++
CFLASGS = -Wall -Werror -Wextra -std=c++98
CFLASGS += -g -fsanitize=address

SRC		= Account.cpp tests.cpp
OBJ 	= $(SRC:%.cpp=$(OBJ_DIR)/%.o)
OBJ_DIR = obj
NAME 	= ex02

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CC) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@echo "Removing $(OBJ_DIR)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Removing $(NAME)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re debug