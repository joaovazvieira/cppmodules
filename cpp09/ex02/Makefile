# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jovieira <jovieira@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/04/14 15:23:11 by jovieira      #+#    #+#                  #
#    Updated: 2025/07/28 22:14:07 by jovieira      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++11 -g
# CFLAGS	+= -fsanitize=address

SRCS	=	main.cpp PmergeMe.cpp

OBJ		=	$(SRCS:%.cpp=$(OBJ_DIR)/%.o)
OBJ_DIR	=	obj
NAME	=	PmergeMe

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compiling
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

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