# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabrito- <mabrito-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/25 19:31:09 by marianamest       #+#    #+#              #
#    Updated: 2024/10/10 19:09:52 by mabrito-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT_PATH = ft_libft
LIBFT = ${LIBFT_PATH}/libft.a

SRCS = pipex.c utils.c

OFILES	= $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

${NAME}: ${LIBFT} ${OFILES}	

	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)

${LIBFT}:
	@make -s -C $(LIBFT_PATH) bonus

clean:
	@make -s -C $(LIBFT_PATH) clean
	rm -f $(OFILES)

fclean: clean
	@make -s -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all