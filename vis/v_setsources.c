#include "../includes/visualiser.h"

void	init_texture(SDL_Texture *tex, t_vis *vis,  char *img_path)
{
	SDL_Surface	*surface;

	surface = IMG_Load(img_path);
	tex = SDL_CreateTextureFromSurface(vis->rend, surface);
	SDL_FreeSurface(surface);
	if (!tex)
		vis_error_free(vis, SDL_GetError());
}

void	setsprites(t_vis *vis)
{
	init_texture(vis->ant[0],vis,  "/home/mattgerber/Documents/damlemon/vis/resources/sprites/1.png");
	init_texture(vis->ant[1],vis,  "/home/mattgerber/Documents/damlemon/vis/resources/sprites/2.png");
	init_texture(vis->ant[2],vis,  "/home/mattgerber/Documents/damlemon/vis/resources/sprites/3.png");
	init_texture(vis->ant[3],vis,  "/home/mattgerber/Documents/damlemon/vis/resources/sprites/4.png");
	init_texture(vis->ant[4],vis,  "/home/mattgerber/Documents/damlemon/vis/resources/sprites/5.png");
	init_texture(vis->ant[5],vis,  "/home/mattgerber/Documents/damlemon/vis/resources/sprites/6.png");
	init_texture(vis->ant[6],vis,  "/home/mattgerber/Documents/damlemon/vis/resources/sprites/7.png");
	init_texture(vis->ant[7],vis,  "/home/mattgerber/Documents/damlemon/vis/resources/sprites/8.png");
	init_texture(vis->ant[8],vis,  "/home/mattgerber/Documents/damlemon/vis/resources/sprites/9.png");
	init_texture(vis->ant[9],vis,  "/home/mattgerber/Documents/damlemon/vis/resources/sprites/10.png");
	vis->ant[10] = NULL;
}

void	setmirror(t_vis *vis)
{
	init_texture(vis->mirror[0], vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/1.png");
	init_texture(vis->mirror[1], vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/2.png");
	init_texture(vis->mirror[2], vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/3.png");
	init_texture(vis->mirror[3], vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/4.png");
	init_texture(vis->mirror[4], vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/5.png");
	init_texture(vis->mirror[5], vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/6.png");
	init_texture(vis->mirror[6], vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/7.png");
	init_texture(vis->mirror[7], vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/8.png");
	init_texture(vis->mirror[8], vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/9.png");
	init_texture(vis->mirror[9], vis, "/home/mattgerber/Documents/damlemon/vis/resources/mirror/10.png");
	vis->mirror[10] = NULL;

}

void			populate_vis(t_vis *vis)
{
	init_window(vis);
	init_renderer(vis);
	vis->active = 0;
	vis->percent = 0.1;
	init_texture(vis->bg, vis, "/home/mattgerber/Documents/damlemon/vis/resources/bg.jpg");
	init_texture(vis->room, vis, "/home/mattgerber/Documents/damlemon/vis/resources/sq.png");
	setsprites(vis);
	setmirror(vis);
}