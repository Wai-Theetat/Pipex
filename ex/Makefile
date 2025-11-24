# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pioncha2 <pioncha2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/24 14:46:20 by pioncha2          #+#    #+#              #
#    Updated: 2025/09/11 15:03:54 by pioncha2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC_DIR = srcs
INC_DIR = includes
LIBFT_DIR = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I $(INC_DIR)
LIBFT = -L $(LIBFT_DIR) -lft

SRC_FILES = pipex.c pipex_utils.c pipex_process.c pipex_cmd.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make --silent -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@
	@echo "\033[32mPipex Compiled!\n\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@echo "\033[31mObject files cleaned!\n\033[0m"

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "\033[31mBinary cleaned!\n\033[0m"

re: fclean all

.PHONY: all clean fclean re