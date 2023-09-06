# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 10:36:01 by jrocha-v          #+#    #+#              #
#    Updated: 2023/09/06 19:00:48 by jrocha-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
OBJS		= utils_libft.o utils_argv.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) main.c $(OBJS) -o $(NAME) && ./pipex ls -l
%.o: %.c
	$(CC) $(CFLAGS) -c $<
	
clean:
	$(RM) $(OBJS)

fe: clean
	$(RM) $(NAME)
	
re: fclean
	$(MAKE) all

.PHONY: all clean fclean re