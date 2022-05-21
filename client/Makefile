# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 20:05:04 by gyumpark          #+#    #+#              #
#    Updated: 2022/05/21 20:08:26 by gyumpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
SRCS =
OBJS = $(SRCS:%.c=%.o)

CC = cc
\CFLAG = -Wall -Wextra -Werror
CFLAG = -fsanitize=address -g3

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
