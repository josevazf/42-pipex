# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 10:36:01 by jrocha-v          #+#    #+#              #
#    Updated: 2023/09/19 11:34:57 by jrocha-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
SRCS_DIR	= src
OBJS_DIR	= objs
INCLUDES	= includes
LIBFT		= ./libft/libft.a
LIBFT_DIR	= ./libft

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MK_FLAG		= --no-print-directory
RM			= rm -rf

SRCS		= main.c utils_argv.c utils_lib.c
OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	echo "Finished!"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(@D)
	$(CC) -I $(INCLUDES) $(CFLAGS) -c $< -o $@

$(LIBFT):
	echo "Compiling necessary libs..."
	$(MAKE) $(MK_FLAG) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS_DIR)
	$(MAKE) $(MK_FLAG) clean -C $(LIBFT_DIR)

fe: clean
	$(RM) $(NAME) $(LIBFT)
	
re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
.SILENT: