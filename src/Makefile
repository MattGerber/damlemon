# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbolton <rbolton@student.wethinkcode.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/26 20:47:24 by rbolton           #+#    #+#              #
#    Updated: 2020/05/29 15:30:14 by rbolton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SRC = ./lemon.c ./ants.c ./artery.c ./bfs.c ./error.c ./free.c ./inputchecks.c ./inputlist.c ./pathing.c ./queue.c ./rooms.c ./testing.c ./visualise.c
LIBS = -I/src ../Libft/libft.a 
FLAGS = -g -Wall -Werror -Wextra
TIMER = lem-in-time
TIMER_SRC = ./timer.c ./ants.c ./artery.c ./bfs.c ./error.c ./free.c ./inputchecks.c ./inputlist.c ./pathing.c ./queue.c ./rooms.c ./testing.c ./visualise.c

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC) $(LIBS) -o ../$(NAME)
	@echo [$(NAME) copiled]

fclean:
	@rm -f ../$(NAME) ../$(TIMER)
	@echo "[lem-in]/[lem-in-time] removed"

re: fclean all 

$(TIMER) :
	@gcc $(FLAGS) $(TIMER_SRC) $(LIBS) -o ../$(TIMER)
	@echo [$(TIMER) copiled]