# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 10:36:01 by jrocha-v          #+#    #+#              #
#    Updated: 2023/09/29 11:39:05 by jrocha-v         ###   ########.fr        #
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
RM			= rm -rf

SRCS		= pipex_main.c pipex_execute.c pipex_path.c
SRCS_BONUS	= pipex_main_bonus.c pipex_execute_bonus.c pipex_path_bonus.c

# Substitute .c with .o 
OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)
OBJS_BONUS	= $(SRCS_BONUS:%.c=$(OBJS_DIR)/%.o)

#default target
all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	echo "Finished!"

bonus: $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME)
	echo "Finished!"

#create .o fies
# $< first prerequisite aka .c; $@ output/target file aka .o
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(@D)
	$(CC) -I $(INCLUDES) $(CFLAGS) -c $< -o $@

$(LIBFT):
	echo "Compiling necessary libs..."
	$(MAKE) -C $(LIBFT_DIR)

#remove .o files
clean:
	$(RM) $(OBJS_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

#reset environment - remove everything and recompile
re: fclean
	$(MAKE) all

#targets declared as .PHONY will force the command even if there is a subdirectory or file with it's name
.PHONY: all clean fclean re
.SILENT: