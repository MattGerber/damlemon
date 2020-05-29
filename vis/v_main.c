#include "../includes/visualiser.h"

void	vis_free(t_vis **vis)
{
	if (vis && *vis)
	{
		SDL_DestroyTexture((*vis)->room);
		SDL_DestroyTexture((*vis)->bg);
		SDL_DestroyRenderer((*vis)->rend);
		SDL_DestroyWindow((*vis)->window);
		SDL_Quit();
		free(*vis);
		(*vis) = NULL;
	}
}

void	vis_error_free(t_vis *vis, const char *error)
{
	if (vis)
		vis_free(&vis);
	ft_putstr_fd((char*)error, 2);
	exit(1);
}

t_vis			*init_vis(void)
{
	t_vis	*vis;

	if (!(vis = (t_vis*)malloc(sizeof(t_vis))))
		vis_error_free(NULL, "vis failed to init");
	vis->window = NULL;
	vis->rend = NULL;
	vis->bg = NULL;
	vis->room = NULL;
	vis->close = 0;
	vis->active = 0;
	vis->percent = 0;
	return (vis);
}

SDL_Window		*init_window(t_vis *vis)
{
	SDL_Window	*win;

	if (!(win = SDL_CreateWindow("Lem-in Visualizer",
						SDL_WINDOWPOS_CENTERED,
						SDL_WINDOWPOS_CENTERED,
						WIDTH, HEIGHT, 0)))
		vis_error_free(vis, SDL_GetError());
	return (win);
}

SDL_Renderer	*init_renderer(t_vis *vis)
{
	SDL_Renderer	*ren;
	int				flags;

	flags = SDL_RENDERER_ACCELERATED;
	if (!(ren = SDL_CreateRenderer(vis->window, -1, flags)))
		vis_error_free(vis, SDL_GetError());
	return (ren);
}

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

void			populate_vis(t_vis *vis)
{
	vis->window = init_window(vis);
	vis->rend = init_renderer(vis);
	vis->bg = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/bg.jpg");
	vis->room = init_texture(vis, "/home/mattgerber/Documents/damlemon/vis/resources/sq.png");
}

void		draw_bg(t_vis *vis)
{
	SDL_Rect	dims;

	dims.w = WIDTH;
	dims.h = HEIGHT;
	dims.x = 0;
	dims.y = 0;
	SDL_RenderCopy(vis->rend, vis->bg, NULL, &dims);
}


void drawlines(t_vis *vis, t_input *input)
{
	t_input *temp;
	int 	i;

	temp = input;
	while(temp)
	{
		if (temp->roomnode)
		{
			i = 0;
			while(temp->roomnode->links[i])
			{
					thickLineColor(vis->rend, temp->roomnode->x,  temp->roomnode->y ,
		 						temp->roomnode->links[i]->x , temp->roomnode->links[i]->y , 8, 0xFFFFFFFF);
				i++;
			}
		}
		 temp = temp->next;

	}

}

void	drawants(t_vis *vis, t_input *moves)
{
	while(moves)
	{
		ft_putendl(moves->line);
		moves = moves->next;
	}
}

void drawrooms(t_vis *vis, t_input *input)
{
	SDL_Rect	dims;
	t_input	*temp;
	dims.w = 100;
	dims.h = 100;
	temp = input;

	while(temp->next)
	{
		if (temp->roomnode)
		{
			dims.x = temp->roomnode->x - (100 / 2);
			dims.y = temp->roomnode->y - (100 / 2);
			if (temp->roomnode->name == "START")
				stringColor(vis->rend, dims.x, dims.y - 20, "START", 0xFFFFFFFF);
			else if (temp->roomnode->name  == "START")
				stringColor(vis->rend, dims.x, dims.y - 20, "END", 0xFFFFFFFF);
			else
				stringColor(vis->rend, dims.x, dims.y - 20, temp->roomnode->name, 0xFFFFFFFF);
			SDL_RenderCopy(vis->rend, vis->room, NULL, &dims);
		}
		temp = temp->next;
	}
}

void	initheart(t_heart *heart)
{
	heart->ants = 0;
	heart->artery = malloc(sizeof(t_artery **));
	*heart->artery = NULL;
	heart->input = NULL;
	heart->inputchecks = NULL;
	heart->network = NULL;
	heart->queue = NULL;
	heart->traffic = NULL;
	heart->buff = NULL;
}

int main()
{
	t_vis *visualiser;
	SDL_Event	event;
	SDL_Rect	dims;
	dims.w = 100;
	dims.h = 100;
	t_heart	*heart;
	t_input	*moves;

	heart = malloc(sizeof(t_heart));
	initheart(heart);
	while (get_next_line(0, &(heart->buff)))
		if (!addinputnode(&heart->input, heart->buff))
			erexit(heart, 2);
	if (!validateinput(heart))
		erexit(heart, 3);
	initroomnodes(heart);
	moves = heart->input;
	while(moves->line[0] != 'L')
		moves = moves->next;
	visualiser = init_vis();
	populate_vis(visualiser);
	while(!(visualiser->close))
	{
		SDL_RenderClear(visualiser->rend);
		draw_bg(visualiser);
		drawlines(visualiser, heart->input);
		drawrooms(visualiser, heart->input);
		drawants(visualiser, moves);
		SDL_RenderPresent(visualiser->rend);
		SDL_Delay(1000 / 60);
		while (SDL_PollEvent(&event))
		{
			if ((event.type == SDL_KEYDOWN) || event.type == SDL_QUIT)
				visualiser->close = 1;
		}
	}
	vis_free(&visualiser);
	freeheart(heart);
	return (0);
}