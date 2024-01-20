# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 11:10:37 by pmarkaid          #+#    #+#              #
#    Updated: 2024/01/20 18:26:05 by pmarkaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
TEST_NAME = tester

SRCS = \
	so_long.c \
	map_is_valid.c \
	error.c \
	map.c \
	free.c \
	utils.c \
	flood_fill.c

TEST_SRCS = \
	test/test_map_is_valid.c \
	test/unity/src/unity.c \
	map_is_valid.c \
	error.c \
	map.c \
	free.c \
	utils.c \
	flood_fill.c

SRCS_DIR = src
SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))

LIBFT_REPO = https://github.com/pmarkaide/42_libft
LIBFT_TAG = v.1.2.0
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJS = $(SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

LIBFT_INCLUDE = -I $(LIBFT_DIR)
TEST_INCLUDE = -I test/unity/src/ -I test/

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

tester: $(TEST_OBJS)
	$(CC) $(CFLAGS) $(LIBFT_INCLUDE) -o $(TEST_NAME) $(TEST_OBJS) $(LIBFT)

clean:
	rm -f $(OBJS)
	rm -rf $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
