# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jovieira <jovieira@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/02/26 16:05:01 by jovieira      #+#    #+#                  #
#    Updated: 2025/05/02 11:33:12 by jovieira      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++11 -g
CFLAGS	+= -fsanitize=address

SRCS	=	main.cpp\
			Parse.cpp\
			ScalarConverter.cpp\

INC		=	Parse.hpp ScalarConverter.hpp
OBJ		=	$(SRCS:%.cpp=$(OBJ_DIR)/%.o)
OBJ_DIR	=	obj
NAME	=	Convert

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