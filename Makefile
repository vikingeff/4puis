# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleger <gleger@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/31 19:03:08 by gleger            #+#    #+#              #
#    Updated: 2014/03/08 18:58:16 by fle-bach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#commentaire
CC		= gcc
NAME	= puissance4
FLAGS	= -Wall -Wextra -Werror -O3 -I ./includes
LIB		= -L /usr/lib -ltermcap
SRC		=	ft_putstuff.c \
			ft_putmore.c \
			ft_check.c \
			ft_board.c \
			ft_play.c \
			ft_str.c \
			p4.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[1;35;m[Linking] \t\t\033[0m: " | tr -d '\n'
	$(CC) $(FLAGS) -o $@ $^ 
	@echo "\033[1;32;m[Success] \t\t\t\033[0m"

%.o: %.c includes/p4.h
	@echo "\033[1;36;m[Compiling $<] \t\033[0m: " | tr -d '\n'
	$(CC) $(FLAGS) -c $<

clean:
	@echo "\033[0;33;m[Cleaning] \t\t\033[0m: " | tr -d '\n'
	rm -f $(OBJ)

fclean: clean
	@echo "\033[0;31;m[Deleting $(NAME)] \t\033[0m: " | tr -d '\n'
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
