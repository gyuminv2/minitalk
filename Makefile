# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 18:15:11 by gyumpark          #+#    #+#              #
#    Updated: 2022/05/21 20:12:08 by gyumpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
C_DIR = ./client
S_DIR = ./server

CC = cc
\CFLAG = -Wall -Wextra -Werror
CFLAG = -fsanitize=address -g3

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(OBJS2)
	$(CC) $(CFLAG) $(SRCS) -o 

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
