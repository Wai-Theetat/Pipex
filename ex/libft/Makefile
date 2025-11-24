# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pioncha2 <pioncha2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/24 14:46:20 by pioncha2          #+#    #+#              #
#    Updated: 2025/09/09 12:48:17 by pioncha2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

#####################################
LIBFT_SRC_DIR = .
LIBFT_INC_DIR = .
LIBFT_SRC_FILES = 	ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_isdigit.c \
					ft_isalpha.c ft_atoi.c ft_strlen.c ft_strlcat.c ft_strncmp.c ft_strdup.c ft_calloc.c \
					ft_memcpy.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_bzero.c ft_memchr.c ft_memcmp.c \
					ft_memset.c ft_memmove.c ft_strlcpy.c ft_itoa.c ft_strjoin.c ft_split.c ft_striteri.c \
					ft_strmapi.c ft_substr.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
					ft_putnbr_fd.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c \
					ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
					ft_lstsize_bonus.c ft_lstlast_bonus.c
LIBFT_HEADER_FILES = libft.h 
LIBFT_HEADERS = $(LIBFT_HEADER_FILES:%.h=$(LIBFT_INC_DIR)/%.h)
LIBFT_SRCS = $(LIBFT_SRC_FILES:%.c=$(LIBFT_SRC_DIR)/%.c)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

#####################################
PRINTF_SRC_DIR = ./ft_printf/
PRINTF_INC_DIR = ./ft_printf/
PRINTF_SRC_FILES = ft_printf.c ft_put_utils.c ft_put_hex_utils.c
PRINTF_HEADER_FILES = ft_printf.h 
PRINTF_HEADERS = $(PRINTF_HEADER_FILES:%.h=$(PRINTF_INC_DIR)/%.h)
PRINTF_SRCS = $(PRINTF_SRC_FILES:%.c=$(PRINTF_SRC_DIR)/%.c)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

#####################################
GNL_SRC_DIR = ./get_next_line/
GNL_INC_DIR = ./get_next_line/
GNL_SRC_FILES = get_next_line_bonus.c get_next_line_utils_bonus.c
GNL_HEADER_FILES = get_next_line_bonus.h
GNL_HEADERS = $(GNL_HEADER_FILES:%.h=$(GNL_INC_DIR)/%.h)
GNL_SRCS = $(GNL_SRC_FILES:%.c=$(GNL_SRC_DIR)/%.c)
GNL_OBJS = $(GNL_SRCS:.c=.o)

#####################################

INCLUDES = -I $(LIBFT_INC_DIR) -I $(PRINTF_INC_DIR) -I $(GNL_INC_DIR)
OBJS = $(LIBFT_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

all: $(NAME)

$(NAME): $(OBJS)
	ar crs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean:
	rm -rf *.o
	rm -rf ft_printf/*.o
	rm -rf get_next_line/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re