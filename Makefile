##########################################################
#                                                         #
#             Makefile for lemon          	           #
#                                                         #
# First compiles the library for use in the project         #
# Before compiling the programs lemon				     #
#                                                         #
##########################################################



all:
	@(cd Libft; $(MAKE) all)
	@(cd src; $(MAKE) all)

clean: 
	@$(MAKE) -C ./Libft clean

fcleanlib:
	@$(MAKE) -C ./Libft fclean

fcleanlemon:
	@$(MAKE) -C ./src fclean

fclean: fcleanlib fcleanlemon

re: fclean all

lem-in-time:
	@$(MAKE) -C ./src lem-in-time




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
