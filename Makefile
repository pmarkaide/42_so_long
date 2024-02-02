# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 11:10:37 by pmarkaid          #+#    #+#              #
#    Updated: 2024/02/02 15:19:27 by pmarkaid         ###   ########.fr        #
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
	flood_fill.c \
	game.c

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

LIB_DIR = lib

LIBFT_REPO = https://github.com/pmarkaide/42_libft
LIBFT_TAG = v.1.2.0
LIBFT_DIR = $(LIB_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX42_REPO = https://github.com/codam-coding-college/MLX42.git
MLX42_DIR = $(LIB_DIR)/MLX42
MLX42_LIBS = $(MLX42_DIR)/build/libmlx42.a -L $(brew --prefix glfw)/lib -lglfw -ldl -pthread -lm
MLX42 = $(MLX42_DIR)/build/libmlx42.a

OBJS = $(SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

LIBFT_INCLUDE = -I $(LIBFT_DIR)
MLX42_INCLUDE = -I $(MLX42_DIR)/include
TEST_INCLUDE = -I test/unity/src/ -I test/

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast

all: $(LIBFT) $(MLX42) $(NAME)

$(LIBFT):
	git clone --branch $(LIBFT_TAG) --single-branch $(LIBFT_REPO) $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

$(MLX42):
	git clone $(MLX42_REPO) $(MLX42_DIR)
	cmake $(MLX42_DIR) -B $(MLX42_DIR)/build
	make -C $(MLX42_DIR)/build -j4

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INCLUDE) $(MLX42_INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MLX42)
	$(CC) $(CFLAGS) $(LIBFT_INCLUDE) -o $(NAME) $(OBJS) $(MLX42_LIBS) $(LIBFT)

tester: $(TEST_OBJS)
	$(CC) $(CFLAGS) $(LIBFT_INCLUDE) -o $(TEST_NAME) $(TEST_OBJS) $(LIBFT)

clean:
	rm -f $(OBJS)
	rm -rf $(LIBFT_DIR)
	rm -rf $(MLX42_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx
