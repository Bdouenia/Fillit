#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 15:29:41 by dvalenti          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2017/11/22 19:04:48 by bdouenia         ###   ########.fr        #
=======
#    Updated: 2017/11/22 19:41:24 by dvalenti         ###   ########.fr        #
>>>>>>> 786d9494810bbe5147b39616e3ea052cf029255e
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
			get_str.c \
			get_tetri.c \
<<<<<<< HEAD
			main.c \
=======
			main.c 

// SRC_DIR= ./src/
>>>>>>> 786d9494810bbe5147b39616e3ea052cf029255e

SRC= $(addprefix src/,$(SRC_FILE))

OBJ = $(SRC:.c=.o)


#	RULES

all: 		$(NAME)

$(NAME):	$(OBJ)
			make -C ./libft
			$(CC) $(CFLAGS) $(CHEADER) $(OBJ) $(LIBA) -o $(NAME)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJ)
			make -C ./libft clean

fclean: 	clean
			rm -f $(NAME)
			make -C ./libft fclean

re: fclean all
