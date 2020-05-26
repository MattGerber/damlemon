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
SRC_LEM = $(SRC_DIR)*.c

all: $(LIB) $(NAME_LEM)

$(LIB): makelib
	@echo "[$(LIB)] compiled"

$(NAME_LEM): $(SRC_LEM)
	@$(CC) $(FLAGS) $(OPTIONS) $(SRC_LEM) -o $(NAME_LEM)
	@echo "[$(NAME_LEM)] compiled"

clean: cleanlib
	@/bin/rm -f $(OBJ_LEM)
	@echo "Object files removed"

fclean: fcleanlib
	@/bin/rm -f $(NAME_LEM)
	@echo "[$(NAME_LEM)] removed"

re: fclean all

makelib:
	@$(MAKE) -C ./Libft all

relib:
	@$(MAKE) -C ./Libft re

cleanlib:
	@$(MAKE) -C ./Libft clean

fcleanlib:
	@$(MAKE) -C ./Libft fclean
	@echo "[$(LIB)] removed"

#OBJS specifies which files to compile as part of the project
OBJ_VIS = vis/*.c
NAME_VIS = visualiser

#CC specifies which compiler we're using

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = visualiser

#This is the target that compiles our executable
$(NAME_VIS) : $(OBJ_VIS)
	$(CC) $(OBJ_VIS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
