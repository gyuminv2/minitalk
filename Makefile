# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 18:15:11 by gyumpark          #+#    #+#              #
#    Updated: 2022/05/22 20:17:17 by gyumpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(NAME_C) $(NAME_S)
NAME_C = client
NAME_S = server
SRCS_C = ./client.c ./ft_atoi.c
SRCS_S = ./server.c
OBJS = $(SRCS_C:%.c=%.o) $(SRCS_S:%.c=%.o)

CC = cc
\CFLAG = -Wall -Wextra -Werror
CFLAG = -fsanitize=address -g3

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS_C) $(OBJS_S)
	$(CC) $(CFLAG) $(SRCS_C) -o $(NAME_C)
	$(CC) $(CFLAG) $(SRCS_S) -o $(NAME_S)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME_C)
	$(RM) $(NAME_S)
	$(RM) *.dSYM

re: fclean all

.PHONY: all clean fclean re
