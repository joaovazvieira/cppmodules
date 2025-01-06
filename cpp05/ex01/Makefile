# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jovieira <jovieira@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/12/04 13:03:11 by jovieira      #+#    #+#                  #
#    Updated: 2025/01/06 14:49:47 by jovieira      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC		=	g++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98 -g
# CFLAGS	+= -fsanitize=address

SRCS	=	main.cpp\
			Bureaucrat.cpp\
			Form.cpp\

INC		=	Bureaucrat.hpp Form.hpp
OBJ		=	$(SRCS:%.cpp=$(OBJ_DIR)/%.o)
OBJ_DIR	=	obj
NAME	=	Bureaucrat

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