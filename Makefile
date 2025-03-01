# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 23:20:17 by val               #+#    #+#              #
#    Updated: 2025/02/26 18:14:00 by vdurand          ###   ########.fr        #
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

VERBOSE = 0

ifeq ($(VERBOSE),1)
    SILENT =
else
    SILENT = @
endif

ifeq ($(VERBOSE),1)
    DUMP_OUT =
else
    DUMP_OUT = > /dev/null 2>&1
endif

##################

NAME = push_swap
NAME_BONUS = checker

SRC_DIR = src
MAIN_DIR = src_main
OBJ_DIR = obj
INC_DIR = includes
LIBS_DIR = libs

SRC_COMMON_FILES = \
	chunks/chunks_methods.c \
	chunks/chunks_moves.c \
	chunks/qsorts_methods.c \
	sort/sort_chunks.c \
	sort/sort_easy.c \
	sort/sort.c \
	stacks_instructions/ins_clean.c \
	stacks_instructions/ins_pushs_swaps.c \
	stacks_instructions/ins_reverse_rotate.c \
	stacks_instructions/ins_rotate.c \
	stacks_instructions/ins_utils.c \
	positions_utils.c \
	utils.c \
	main_utils.c

SRC_CHECKER_FILES = \
	checker/checker_main.c

SRC_COMMON = $(addprefix $(SRC_DIR)/, $(SRC_COMMON_FILES))
SRC_CHECKER = $(addprefix $(SRC_DIR)/, $(SRC_CHECKER_FILES))

SRC_MAIN = $(SRC_COMMON) $(SRC_DIR)/main.c
SRC_BONUS = $(SRC_COMMON) $(SRC_CHECKER)

OBJ = $(SRC_MAIN:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS = $(SRC_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBS_DIRS = $(shell find $(LIBS_DIR) -mindepth 1 -type d)
LIBS = $(foreach dir, $(LIBS_DIRS), $(dir)/$(notdir $(dir)).a)

CC = gcc
CFLAGS = -Werror -Wextra -Wall
LIBS_NO_LIB =  $(patsubst lib%, %, $(patsubst %.a, %, $(notdir $(LIBS))))
LDFLAGS = $(addprefix -L, $(LIBS_DIRS)) $(addprefix -l, $(LIBS_NO_LIB))
INCLUDES = $(LDFLAGS) -I$(INC_DIR) $(addprefix -I, $(LIBS_DIRS))

.PHONY: all
all: $(NAME)

.PHONY: bonus
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBS)
	$(SILENT) $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "$(BG_GREEN)>>> Program $(NAME_BONUS) compiled!$(RESET)"
	
$(NAME): $(OBJ) $(LIBS)
	$(SILENT) $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "$(BG_GREEN)>>> Program $(NAME) compiled!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile $(INC_DIR)/push_swap.h
	$(SILENT) mkdir -p $(dir $@)
	@echo "$(BLUE)>>> Compiling $<...$(RESET)"
	$(SILENT) $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBS): %.a:
	$(SILENT) echo "$(MAGENTA)>>> Compiling library $(notdir $@)...$(RESET)"
	$(SILENT) $(MAKE) -C $(dir $@) > /dev/null 2> make_errors.log; \
	if [ $$? -ne 0 ]; then \
		echo "$(RED)>>> Error while compiling $(notdir $@):$(RESET)"; \
		cat make_errors.log; \
		rm -f make_errors.log; \
		echo "$(RED)>>> Error -----------------------------$(RESET)"; \
		exit 1; \
	fi; \
	rm -f make_errors.log
	$(SILENT) if $(MAKE) -C $(dir $@) -n bonus $(DUMP_OUT); then \
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

.PHONY: fcleanlibs
fcleanlibs:
	$(SILENT) for dir in $(LIBS_DIRS); do \
		if [ -f $$dir/Makefile ]; then \
			$(MAKE) -C $$dir fclean $(DUMP_OUT); \
			echo "$(GREEN)>>> Cleaned all in $$dir$(RESET)"; \
		fi \
	done

.PHONY: clean
clean:
	@echo "$(YELLOW)>>> Cleaning objects$(RESET)"
	$(SILENT) rm -rf $(OBJ_DIR) $(DUMP_OUT)

.PHONY: fclean
fclean: clean fcleanlibs
	@echo "$(YELLOW)>>> Cleaning executable...$(RESET)"
	$(SILENT) rm -f $(NAME) $(DUMP_OUT)
	$(SILENT) rm -f $(NAME_BONUS) $(DUMP_OUT)

.PHONY: re
re: fclean all
