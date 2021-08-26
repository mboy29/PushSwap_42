# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboy <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 13:36:05 by mboy              #+#    #+#              #
#    Updated: 2021/01/27 11:07:58 by mboy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_strlen.c\
		ft_isdigit.c\
		ft_atoi.c\
		ft_atol.c\
		ft_swap.c\
		ft_split.c\
		ft_putstr_fd.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3 -I.

all : $(NAME)

$(NAME) : $(OBJ)
	ar rsc  $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ) $(OBJB)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean all re
