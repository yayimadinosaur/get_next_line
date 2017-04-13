# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfung <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 08:16:24 by wfung             #+#    #+#              #
#    Updated: 2017/04/13 16:20:35 by wfung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	gnl

CC		=	gcc

FLAG	=	-Wall -Wextra -Werror

SRCS	= 	main.c \
			get_next_line_original.c
	   		
OBJ =		${SRCS:.c=.o}

INCLUDE	=	-I ./libft/ -L ./libft -lft

all: $(NAME)

$(OBJ): $(SRCS)
		@$(CC) $(FLAG) -c $*.c

$(NAME): $(OBJ)
		@make all -C libft
		@$(CC) $(FLAG) $(INCLUDE) $(OBJ) -o $(NAME)

clean:
		@make clean -C libft
		@/bin/rm -f $(OBJ)

fclean: clean
		@make fclean -C libft
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
