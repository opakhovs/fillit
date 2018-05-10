# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 18:30:46 by opakhovs          #+#    #+#              #
#    Updated: 2017/10/25 19:11:58 by opakhovs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

all: $(NAME)

$(NAME):
		make re -C libft
		gcc -Wall -Werror -Wextra -o $(NAME) tet.c ft_readfile.c mapping.c ft_tetadd.c ./libft/libft.a -I ./bin/ -I ./libft/
clean:
		make clean -C libft
		/bin/rm -f tet.o ft_readfile.o mapping.o ft_tetadd.o

fclean: clean
		make fclean -C libft
		/bin/rm -f $(NAME)

re: fclean all