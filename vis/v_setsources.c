#include "../includes/visualiser.h"

SDL_Texture		*init_texture(t_vis *vis, char *img_path)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	surface = IMG_Load(img_path);
	texture = SDL_CreateTextureFromSurface(vis->rend, surface);
	SDL_FreeSurface(surface);
	if (!texture)
		vis_error_free(vis, SDL_GetError());
	return (texture);
}

SDL_Texture	**setsprites(t_vis *vis)
{
	SDL_Texture **sprites;


	sprites = malloc(11 * sizeof(SDL_Texture *));
	sprites[0] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/1.png");
	sprites[1] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/2.png");
	sprites[2] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/3.png");
	sprites[3] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/4.png");
	sprites[4] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/5.png");
	sprites[5] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/6.png");
	sprites[6] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/7.png");
	sprites[7] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/8.png");
	sprites[8] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/9.png");
	sprites[9] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/10.png");
	sprites[10] = NULL;
	return(sprites);
}

SDL_Texture	**setmirror(t_vis *vis)
{
	SDL_Texture **sprites;

	sprites = malloc(11 * sizeof(SDL_Texture *));
	sprites[0] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_1.png");
	sprites[1] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_2.png");
	sprites[2] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_3.png");
	sprites[3] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_4.png");
	sprites[4] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_5.png");
	sprites[5] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_6.png");
	sprites[6] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_7.png");
	sprites[7] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_8.png");
	sprites[8] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_9.png");
	sprites[9] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_10.png");
	sprites[10] = NULL;
	return(sprites);
}

void			populate_vis(t_vis *vis)
{
	vis->window = init_window(vis);
	vis->rend = init_renderer(vis);
	vis->active = 0;
	vis->percent = 0.1;
	vis->bg = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/bg.jpg");
	vis->room = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sq.png");
	vis->ant = setsprites(vis);
	vis->mirror = setmirror(vis);
}