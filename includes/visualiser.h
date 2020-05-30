#ifndef VISUALISER_H
# define VISUALISER_H

# include "../Libft/libft.h"
# include "lemon.h"
# include <stdbool.h>
# include <SDL2/SDL.h>
# include <GL/glew.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL2_gfxPrimitives.h>

# define WIDTH 1920
# define HEIGHT 1080
# define KEY_N event.key.keysym.scancode == SDL_SCANCODE_N
# define KEY_Q event.key.keysym.scancode == SDL_SCANCODE_Q
# define KEY_R event.key.keysym.scancode == SDL_SCANCODE_R

typedef struct			s_vis
{
	SDL_Window			*window;
	SDL_Renderer		*rend;
	SDL_Texture			*room;
	SDL_Texture			*bg;
	SDL_Texture			**ant;
	SDL_Texture			**mirror;
	int					close;
	int					active;
	double				percent;
}						t_vis;

typedef struct			s_ant
{
	int					id;
	int					active;
	struct s_network	*room;
	struct s_network	*prev;
	struct s_ant		*next;
}						t_ant;

int	v_atoi(const char *str);
int		v_addinputnode(t_input **inputList, char *line);
void	v_freeinputlist(t_input *inputlist);
void	v_initchecks(t_inputchecks *checks);
int		v_runinputchecks(t_heart *heart);
int		v_validateinput(t_heart *heart);

#endif