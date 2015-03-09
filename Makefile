
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/05 16:58:05 by aemebiku          #+#    #+#              #
#    Updated: 2015/03/09 13:51:34 by aemebiku         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC	= main.c \
	  list_linked.c \
	  swap.c \
	  minilib.c \
	  disp.c  \
	  ft_error.c \
		ft_complet.c

NAME	= push_swap

OBJ	= $(SRC:.c=.o)

CC	= gcc -Wall -Wextra -Werror

RM	= rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
