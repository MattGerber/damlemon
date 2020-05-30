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
OPTIONS = ./Libft/libft.a
HDR = ./includes/lemon.h

OBJ_LEM = src/*.c 
# OBJ_LEM += $(OBJ_DIR)lemon.o $(OBJ_DIR)ants.o $(OBJ_DIR)free.o 
# OBJ_LEM += $(OBJ_DIR)artery.o $(OBJ_DIR)bfs.o $(OBJ_DIR)error.o
# OBJ_LEM += $(OBJ_DIR)queue.o $(OBJ_DIR)rooms.o $(OBJ_DIR)testing.o
# OBJ_LEM += $(OBJ_DIR)visualise.o $(OBJ_DIR)pathing.o 

all: $(LIB) $(NAME_LEM)

$(LIB): 
	@$(MAKE) -C Libft
	@echo "[$(LIB)] compiled"

# %.o: $(SRC_DIR)%.c $(HDR)
# 	@$(CC) $(FLAGS) $(OPTIONS) -c $< -o $@

$(NAME_LEM): $(OBJ_LEM)
	@$(CC) $(FLAGS) $(OBJ_LEM) $(OPTIONS) -o $(NAME_LEM)
	@echo "[$(NAME_LEM)] compiled"
	# gcc src/*.c Libft/libft.a includes/lemon.h -o lemon

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


	#OBJS specifies which files to compile as part of the project
OBJ_VIS = vis/*.c
NAME_VIS = visualiser 

#CC specifies which compiler we're using

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_gfx -lSDL2_ttf 

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = visualiser

#This is the target that compiles our executable
$(NAME_VIS) : $(OBJ_VIS)
	$(CC) $(OBJ_VIS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME) $(OPTIONS)
