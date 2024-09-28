# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marianamestre <marianamestre@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/25 19:31:09 by marianamest       #+#    #+#              #
#    Updated: 2024/09/18 13:52:38 by marianamest      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT = ft_libft

SRCS = pipex.c utils.c

OFILES	= $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

${NAME} : ${OFILES}	

	$(CC) $(CFLAGS) -Lft_libft -lft $(OFILES) -o $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all