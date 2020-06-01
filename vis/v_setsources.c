#include "../includes/visualiser.h"

/*
** Creates a texture from an image and returns so a pointer is created
*/

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

/*
** Creates an array of sprites for the animation 
*/

void	setsprites(t_vis *vis)
{


	vis->ant[0] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/1.png");
	vis->ant[1] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/2.png");
	vis->ant[2] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/3.png");
	vis->ant[3] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/4.png");
	vis->ant[4] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/5.png");
	vis->ant[5] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/6.png");
	vis->ant[6] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/7.png");
	vis->ant[7] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/8.png");
	vis->ant[8] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/9.png");
	vis->ant[9] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sprites/10.png");
	vis->ant[10] = NULL;
}

/*
** Creates an array of mirror images so sprite can change directions
*/

void	setmirror(t_vis *vis)
{

	vis->mirror[0] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_1.png");
	vis->mirror[1] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_2.png");
	vis->mirror[2] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_3.png");
	vis->mirror[3] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_4.png");
	vis->mirror[4] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_5.png");
	vis->mirror[5] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_6.png");
	vis->mirror[6] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_7.png");
	vis->mirror[7] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_8.png");
	vis->mirror[8] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_9.png");
	vis->mirror[9] = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/m_10.png");
	vis->mirror[10] = NULL;

}

/*
** set pointers in visualiser struct
*/

void			populate_vis(t_vis *vis)
{
	vis->window = init_window(vis);
	vis->rend = init_renderer(vis);
	vis->active = 0;
	vis->percent = 0.1;
	vis->bg = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/bg.jpg");
	vis->room = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sq.png");
	setsprites(vis);
	setmirror(vis);
}