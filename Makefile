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

fcleanvisualiser:
	@$(MAKE) -C ./vis fclean

fclean: fcleanlib fcleanlemon fcleanvisualiser
	@rm -f output.txt

re: fclean all

visualiser:
	@(cd Libft; $(MAKE) all)
	@(cd vis; $(MAKE) all)

lem-in-time:
	@$(MAKE) -C ./src lem-in-time




