# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: val <val@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 23:20:17 by val               #+#    #+#              #
#    Updated: 2025/02/12 01:24:23 by val              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	ANSI TEXT COLORS
BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m

#	ANSI BACKGROUND COLORS
BG_BLACK = \033[40m
BG_RED = \033[41m
BG_GREEN = \033[42m
BG_YELLOW = \033[43m
BG_BLUE = \033[44m
BG_MAGENTA = \033[45m
BG_CYAN = \033[46m
BG_WHITE = \033[47m

#	STYLES
BOLD = \033[1m
DIM = \033[2m
ITALIC = \033[3m
UNDERLINE = \033[4m
BLINK = \033[5m
REVERSE = \033[7m
HIDDEN = \033[8m

RESET = \033[0m

NAME = push_swap

SRC_DIR = src
MAIN_DIR = src_main
OBJ_DIR = obj
INC_DIR = includes
LIBS_DIR = libs

SRC = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBS_DIRS = $(shell find $(LIBS_DIR) -mindepth 1 -type d)
LIBS = $(foreach dir, $(LIBS_DIRS), $(dir)/$(notdir $(dir)).a)

CC = gcc
CFLAGS = -Werror -Wextra -Wall
LIBS_NO_LIB =  $(patsubst lib%, %, $(patsubst %.a, %, $(notdir $(LIBS))))
LDFLAGS = $(addprefix -L, $(LIBS_DIRS)) $(addprefix -l, $(LIBS_NO_LIB))
INCLUDES = $(LDFLAGS) -I$(INC_DIR) $(addprefix -I, $(LIBS_DIRS))

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "$(BG_GREEN)>>> Program $(NAME) compiled!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile $(INC_DIR)/*.h
	@mkdir -p $(dir $@)
	@echo "$(BLUE)>>> Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBS): %.a:
	@echo "$(MAGENTA)>>> Compiling library $(notdir $@)...$(RESET)"
	@$(MAKE) -C $(dir $@) > /dev/null 2> make_errors.log; \
	if [ $$? -ne 0 ]; then \
		echo "$(RED)>>> Error while compiling $(notdir $@):$(RESET)"; \
		cat make_errors.log; \
		rm -f make_errors.log; \
		echo "$(RED)>>> Error -----------------------------$(RESET)"; \
		exit 1; \
	fi; \
	rm -f make_errors.log
	@if $(MAKE) -C $(dir $@) -n bonus > /dev/null 2>&1; then \
		echo "$(DIM)$(MAGENTA)>>> Bonus rule exists, compiling with bonus...$(RESET)"; \
		$(MAKE) -C $(dir $@) bonus > /dev/null 2> make_errors.log; \
		if [ $$? -ne 0 ]; then \
			echo "$(RED)>>> Error while compiling bonus for $(notdir $@):$(RESET)"; \
			cat make_errors.log; \
			rm -f make_errors.log; \
			echo "$(RED)>>> Error -----------------------------$(RESET)"; \
			exit 1; \
		fi; \
		rm -f make_errors.log; \
	fi
	@echo "$(BG_BLUE)$(GREEN)>>> Compilation of $(notdir $@) completed!$(RESET)"

fcleanlibs:
	@for dir in $(LIBS_DIRS); do \
		if [ -f $$dir/Makefile ]; then \
			$(MAKE) -C $$dir fclean > /dev/null 2>&1; \
			echo "$(GREEN)>>> Cleaned all in $$dir$(RESET)"; \
		fi \
	done

clean:
	@echo "$(YELLOW)>>> Cleaning objects$(RESET)"
	@rm -rf $(OBJ_DIR) > /dev/null 2>&1

fclean: clean fcleanlibs
	@echo "$(YELLOW)>>> Cleaning executable...$(RESET)"
	@rm -f $(NAME) > /dev/null 2>&1

re: fclean all

.PHONY: all fcleanlibs clean fclean re compile_libs