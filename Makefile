# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcantell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 18:26:37 by mcantell          #+#    #+#              #
#    Updated: 2024/03/16 14:51:26 by mcantell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAMEBONUS = pipex_bonus
CFLAGS = -Wall -Werror -Wextra

SRC =	get_next_line.c get_next_line_utils.c ft_substr.c ft_strlen.c\
		ft_strnstr.c ft_strlcpy.c ft_strjoin.c ft_split.c main.c\

OBJ = $(SRC: .c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clear:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJ)
	gcc -o $(NAME) $(OBJ)
	
%.o: %.c
	gcc $(CFLAGS) -c $< -o $@
.PHONY: all, clean, fclean, re