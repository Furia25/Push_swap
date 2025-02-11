# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: val <val@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 21:41:19 by val               #+#    #+#              #
#    Updated: 2025/02/11 23:51:52 by val              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = libstack.a

BASE_SRC = stack_init.c stack_methods.c

ALL_OBJS = $(BASE_SRC:.c=.o)

all: $(NAME) 

$(NAME): $(ALL_OBJS)
	ar rcs $(NAME) $(ALL_OBJS)

%.o: %.c $(INCLUDE_DIR) Makefile
	$(CC) $(CFLAGS) -o ./$@ -c $< -I../libft

clean:
	rm -rf $(ALL_OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
