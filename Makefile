# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 18:26:37 by mcantell          #+#    #+#              #
#    Updated: 2024/06/04 12:30:56 by mcantell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CFLAGS = -Wall -Werror -Wextra

SRC =	corrupt_cop.c ft_split.c ft_strcmp.c ft_strjoin.c ft_strlcpy.c\
		ft_strlen.c ft_strnstr.c ft_substr.c ft_free.c\
		main.c super_split_utils.c super_split.c utils.c jump.c\

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@


OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

all: $(NAME)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all, clean, fclean, re
