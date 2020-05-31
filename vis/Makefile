NAME = visualiser
SRC = ./*.c 
LEM_SRC = ../src/error.c ../src/inputchecks.c ../Libft/libft.a
FLAGS = -w -g -Wall -Werror -Wextra
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_gfx -lSDL2_ttf 


all: $(NAME)

$(NAME):
	@gcc $(SRC) $(LEM_SRC) $(FLAGS) $(LINKER_FLAGS) -o ../$(NAME) 
	@echo [$(NAME) copiled]

fclean:
	@rm -f ../$(NAME) 
	@echo "[visualiser] removed"

re: fclean all