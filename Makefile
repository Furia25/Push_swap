# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: val <val@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 23:20:17 by val               #+#    #+#              #
#    Updated: 2025/02/11 19:43:55 by val              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
RESET = \033[0m
BG_GREEN = \033[42m

NAME = push_swap

SRC_DIR = src
MAIN_DIR = src_main
OBJ_DIR = obj
INC_DIR = includes
LIBS_DIR = libs

SRC = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
LIBS = $(shell find $(LIBS_DIR) -type f -name "*.a")
LIBS_DIRS = $(shell find $(LIBS_DIR) -type d)

CC = gcc
CFLAGS = -Werror -Wextra -Wall
LDFLAGS = $(addprefix -L, $(dir $(LIBS))) $(addprefix -l, $(notdir $(LIBS)))
INCLUDES = -I$(INC_DIR) -I$(LDFLAGS)

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "$(BG_GREEN)>>> Program $(NAME) compiled!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile $(INC_DIR)/*.h | $(OBJ_DIR)
	@echo "$(BLUE)>>> Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@echo "$(YELLOW)>>> Directory '$(OBJ_DIR)' created!$(RESET)"
	@mkdir -p $(OBJ_DIR)

$(LIBS_DIR)/%/Makefile:
	@echo "$(BLUE)>>> Found Makefile in $@, running 'make'...$(RESET)"
	@$(MAKE) -C $@ > /dev/null 2>&1
	@echo "$(GREEN)>>> Compilation of library in $@ completed!$(RESET)"

cleanlibs:
	@echo "$(YELLOW)>>> Cleaning libs...$(RESET)"
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null 2>&1

clean:
	@echo "$(YELLOW)>>> Cleaning objects$(RESET)"
	@rm -rf $(OBJ_DIR) > /dev/null 2>&1

fclean: clean cleanlibs
	@echo "$(YELLOW)>>> Cleaning executable...$(RESET)"
	@rm -f $(NAME) > /dev/null 2>&1

re: fclean all

.PHONY: all cleanlibs clean fclean re