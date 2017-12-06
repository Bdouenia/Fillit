#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 15:29:41 by dvalenti          #+#    #+#              #
#    Updated: 2017/12/06 15:48:32 by dvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: re, clean, fclean, all

CC= gcc

HEADER= includes

LIBA= -L./libft/ -lft

CFLAGS= -Wall -Wextra -Werror

CHEADER= -I $(HEADER)

NAME= fillit

SRC_FILE=	check_tetri.c \
			get_tetri.c \
			main.c \
			map.c \
			solve.c \

SRC= $(addprefix src/,$(SRC_FILE))

OBJ = $(SRC:.c=.o)


#	RULES

all: 		$(NAME)

$(NAME):	$(OBJ)
			@make -C ./libft
			$(CC) $(CFLAGS) $(CHEADER) $(OBJ) $(LIBA) -o $(NAME)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJ)
			@make -C ./libft clean

fclean: 	clean
			rm -f $(NAME)
			@make -C ./libft fclean

re: fclean all
