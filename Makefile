# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 16:38:24 by tberube-          #+#    #+#              #
#    Updated: 2022/05/26 10:48:09 by tberube-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
CC = gcc
HEADER = pipex

NAME = push_swap
SRCS = 	main.c 

LIBFT_PATH = libft/

OBJS = ${SRCS:.c=.o}

$(NAME):	$(OBJS)
	@make -C $(LIBFT_PATH) all
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH)libft.a -o $(NAME)

.c.o:
	${CC} $(CFLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)

all:	$(NAME)

debug:	CFLAGS += -g
debug:	$(NAME)

clean:
	rm -f $(OBJS)
	@make clean -C $(LIBFT_PATH)

fclean:		clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
