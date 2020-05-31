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

int						v_atoi(const char *str);
int						v_addinputnode(t_input **inputList, char *line);
void					v_freeinputlist(t_input *inputlist);
void					v_initchecks(t_inputchecks *checks);
int						v_runinputchecks(t_heart *heart);
int						v_validateinput(t_heart *heart);
void					draw_bg(t_vis *vis);
void					drawlines(t_vis *vis, t_input *input);
void					drawrooms(t_vis *vis, t_input *input);
void							drawants(t_vis *vis, t_ant *input);
void					execmove(t_ant	*ants, char *move, t_input *rooms);
void					init_vis(t_vis *vis);
void					init_window(t_vis *vis);
void					init_renderer(t_vis *vis);
void					init_texture(SDL_Texture *tex, t_vis *vis, char *img_path);
void					populate_vis(t_vis *vis);
void					vis_free(t_vis *vis);
void					vis_error_free(t_vis *vis, const char *error);
void					setsprites(t_vis *vis);
void					setmirror(t_vis *vis);
void					populate_vis(t_vis *vis);
t_ant					*v_initants(int ants);
t_ant					*setstart(t_ant *ant, t_input *input);
void					drawall(t_vis *visualiser, t_heart *heart, t_ant *ants);
void					init_loop(t_vis *visualiser, t_heart *heart);
void					vis_loop(t_vis *visualiser, t_heart *heart, t_ant *ants, t_input *movelist);
int						eventcheck(t_vis *visualiser, t_heart *heart, t_ant *ants, t_input *movelist);
void					free_ants(t_ant *ants);

#endif