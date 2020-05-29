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

typedef struct		s_vis
{
	SDL_Window		*window;
	SDL_Renderer	*rend;
	SDL_Texture		*room;
	SDL_Texture		*bg;
	int				close;
	int				active;
	double			percent;
}					t_vis;

typedef	struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				type;
	struct s_room	*next;
}					t_room;

#endif