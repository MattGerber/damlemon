# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbolton <rbolton@student.wethinkcode.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/26 20:47:24 by rbolton           #+#    #+#              #
#    Updated: 2020/05/26 21:13:57 by rbolton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SRC = ./*.c
LIBS = -I/src ../Libft/libft.a 
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC) $(LIBS) -o ../$(NAME)
	@echo [$(NAME) copiled]

fclean:
	@rm -f ../$(NAME)
	@echo "[lem-in] removed"

re: fclean all 