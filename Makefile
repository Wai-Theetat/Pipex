# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 11:40:51 by tdharmar          #+#    #+#              #
#    Updated: 2025/11/21 13:15:26 by tdharmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	pipex
# BONUS_NAME		:=	checker

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror -g3

INC_DIR			:=	includes/	
SRC_DIR			:=	srcs/

SRCS_FILES		:=	main.c \
					pipex/pipex.c \
					utils/open_file.c utils/error_exit.c utils/cmd_checker.c

SRCS			:=	$(SRCS_FILES:%.c=$(SRC_DIR)%.c)
OBJS			:=	$(SRCS:%.c=%.o)

# UTILS_OBJS		:=	$(filter-out $(SRC_DIR)main.o, $(OBJS))

# BONUS_DIR		:=	bonus/
# BONUS_FILES		:=	checker.c get_next_line.c get_next_line_utils.c

# BONUS			:=	$(BONUS_FILES:%.c=$(BONUS_DIR)%.c)
# BONUS_OBJS		:=	$(BONUS:%.c=%.o)

all: $(NAME) Makefile

$(NAME): $(OBJS) Makefile
	@make -C libft
	@cp libft/libft.a .
	${CC} ${CFLAGS} -I${INC_DIR} ${OBJS} libft.a -o $@

$(OBJS): %.o:%.c
	${CC} ${CFLAGS} -I${INC_DIR} -c $< -o $@

clean:
	rm -rf ${OBJS}
	rm -rf ${BONUS_OBJS}
	rm -rf ${UTILS_OBJS}
	@make -C libft clean

fclean: clean
	rm -f ${NAME}
	rm -rf libft.a
	rm -rf ${BONUS_NAME}
	@make -C libft fclean

re: fclean all

# bonus:	$(BONUS_NAME)

# $(BONUS_NAME): $(BONUS_OBJS) $(UTILS_OBJS) Makefile
# 	@make -C libft
# 	@cp libft/libft.a .
# 	${CC} ${CFLAGS} -I${INC_DIR} $(BONUS_OBJS) $(UTILS_OBJS) libft.a -o $@

# $(BONUS_OBJS): %.o : %.c
# 	${CC} ${CFLAGS} -I${INC_DIR} -c $< -o $@

.PHONY: all clean fclean re