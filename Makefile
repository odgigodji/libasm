# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namerei <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 18:21:56 by namerei           #+#    #+#              #
#    Updated: 2021/05/05 18:22:12 by namerei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s ft_write.s ft_read.s

OBJ = ft_strlen.o ft_strcpy.o ft_strcmp.o ft_strdup.o ft_write.o ft_read.o

all: $(OBJ) $(NAME)

%.o : %.s
	nasm -f macho64 $< -o $@

$(NAME): $(SRC) main.c
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
