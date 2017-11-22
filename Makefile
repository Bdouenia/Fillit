#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 15:29:41 by dvalenti          #+#    #+#              #
#    Updated: 2017/11/22 18:59:45 by dvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: re, clean, fclean, all

CC= gcc

HEADER= includes/libft.h\
		includes/fillit.h

LIBA`= -L./libft/ -lft

CFLAGS= -Wall -Wextra -Werror

CHEADER= -I $(HEADER)

NAME= fillit

SRC_FILE=	check_tetri.c \
			get_str.c \
			get_tetri.c \
			main.c \
SRC_DIR= ./src/

SRC= $(addprefix src/,$(SRC_FILE))

OBJ = $(SRC:.c=.o)


#	RULES

all: 		$(NAME)

$(NAME):	$(OBJ)
			make -C ./libft
			$(CC) $(CFLAGS) $ $(CHEADER) -c ./src/$(OBJ) $(LIBA) -o $(NAME)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJ)
			make -C ./libft clean

fclean: 	clean
			rm -f $(NAME)
			make -C ./libft fclean

re: fclean all
