# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmccain <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 12:37:01 by cmccain           #+#    #+#              #
#    Updated: 2016/12/08 13:01:56 by cmccain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =	main.c \
		solver/create_array.c \
		solver/check_errors.c \
		solver/new_list.c \
		solver/solver.c

LIBDIR = ./libft/

LIBFT = $(addprefix $(LIBDIR), libft.a)

all: $(SRCS) $(LIBFT)
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRCS) -L$(LIBDIR) -lft

$(LIBFT):
	make -C $(LIBDIR)

clean:
	/bin/rm -rf $(NAME)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
