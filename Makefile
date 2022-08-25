# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 22:12:13 by abouhaga          #+#    #+#              #
#    Updated: 2022/04/10 01:15:09 by abouhaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = pipex

CFLAGS = -Wall -Wextra -Werror

SRCS = 	pipex_utils.c \
		pipex.c \
		extended_funcs.c \
		extended_utils_funcs.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean

	rm -f $(NAME)

re: fclean all
