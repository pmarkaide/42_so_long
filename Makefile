# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 11:10:37 by pmarkaid          #+#    #+#              #
#    Updated: 2024/01/18 16:14:43 by pmarkaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRCS = \
	so_long.c \
	map_is_valid.c \
	error.c \
	map.c \
	free.c

LIBFT_REPO = https://github.com/pmarkaide/42_libft
LIBFT_TAG = v.1.2.0
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJS = $(SRCS:.c=.o)

LIBFT_INCLUDE = -I $(LIBFT_DIR)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INCLUDE) -c $< -o $@

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT_INCLUDE) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	git clone --branch $(LIBFT_TAG) --single-branch $(LIBFT_REPO) $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	rm -rf $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
