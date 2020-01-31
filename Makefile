##########################################################
#                                                         #
#             Makefile for lemon          	           #
#                                                         #
# First compiles the library for use in the project         #
# Before compiling the programs lemon				     #
#                                                         #
##########################################################

LIB = libft
NAME_LEM = lemon
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC_DIR = ./src/
INC_DIR = ./includes/
OBJ_DIR = ./src/
OPTIONS = -I$(INC_DIR) -I./Libft -lft -L./Libft
HDR = ./includes/lemon.h

OBJ_LEM = $(OBJ_DIR)inputchecks.o $(OBJ_DIR)inputlist.o
OBJ_LEM += $(OBJ_DIR)lemon.o $(OBJ_DIR)misc.o $(OBJ_DIR)pump.o
OBJ_LEM += $(OBJ_DIR)artery.o $(OBJ_DIR)bfs.o $(OBJ_DIR)error.o
OBJ_LEM += $(OBJ_DIR)queue.o $(OBJ_DIR)rooms.o $(OBJ_DIR)testing.o
OBJ_LEM += $(OBJ_DIR)traffic.o $(OBJ_DIR)vein.o $(OBJ_DIR)visualise.o

all: $(LIB) $(NAME_LEM)

$(LIB): relib cleanlib
	@echo "[$(LIB)] compiled"

%.o: $(SRC_DIR)%.c $(HDR)
	@$(CC) $(FLAGS) $(OPTIONS) -c $< -o $@

$(NAME_LEM): $(OBJ_LEM)
	@$(CC) -o $(NAME_LEM) $(FLAGS) $(OPTIONS) $(OBJ_LEM) 
	@echo "[$(NAME_LEM)] compiled"

clean: cleanlib
	@/bin/rm -f $(SRC_DIR)*.o
	@echo "Object files removed"

fclean: clean fcleanlib
	@/bin/rm -f $(NAME_LEM)
	@echo "[$(NAME_LEM)] removed"

re: fclean all

relib:
	@$(MAKE) -C ./Libft re

cleanlib:
	@$(MAKE) -C ./Libft clean

fcleanlib: cleanlib
	@$(MAKE) -C ./Libft fclean
