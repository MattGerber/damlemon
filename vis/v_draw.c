#include "../includes/visualiser.h"

/*
** Renders the background on the created window
*/

void		draw_bg(t_vis *vis)
{
	SDL_Rect	dims;

	dims.w = WIDTH;
	dims.h = HEIGHT;
	dims.x = 0;
	dims.y = 0;
	SDL_RenderCopy(vis->rend, vis->bg, NULL, &dims);
}

/*
** Renders links between rooms on the created window
*/

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

/*
** Renders rooms on the created window
*/

void drawrooms(t_vis *vis, t_input *input)
{
	SDL_Rect	dims;
	t_input	*temp;
	dims.w = 100;
	dims.h = 100;
	temp = input;

	while(temp)
	{
		if (temp->roomnode)
		{
			dims.x = temp->roomnode->x - (100 / 2);
			dims.y = temp->roomnode->y - (100 / 2);
			if (temp->roomnode->start)
				stringColor(vis->rend, dims.x, dims.y - 20, "START", 0xFF000000);
			else if (temp->roomnode->end)
				stringColor(vis->rend, dims.x, dims.y - 20, "END", 0xFF000000);
			else
				stringColor(vis->rend, dims.x, dims.y - 20, temp->roomnode->name, 0xFF000000);
			SDL_RenderCopy(vis->rend, vis->room, NULL, &dims);
		}
		temp = temp->next;
	}
}

/*
** Renders rooms on the created window
*/

void	drawants(t_vis *vis, t_ant *input)
{
	SDL_Rect	dims;
	t_ant	*temp;
	dims.w = 50;
	dims.h = 50;
	temp = input;
	int i;

	while(temp)
	{
		if (vis->active && temp)
		{
			if(temp->room && temp->prev){
				dims.x = temp->prev->x - (100 / 2) + (temp->room->x - temp->prev->x) * vis->percent;
 				dims.y = temp->prev->y - (100 / 2) + (temp->room->y - temp->prev->y) * vis->percent;
			}
		}
		else if (temp)
		{
			dims.x = temp->room->x - 20;
			dims.y = temp->room->y - 20;
		}
		i = vis->percent * 10;

			if (temp->prev && temp->room->x < temp->prev->x)
				SDL_RenderCopy(vis->rend, vis->ant[i], NULL, &dims);
			else
				SDL_RenderCopy(vis->rend, vis->mirror[i], NULL, &dims);
	
			temp = temp->next;


	}
}

/*
** Calls all the draw function
*/

void	drawall(t_vis *visualiser, t_heart *heart, t_ant *ants)
{
	draw_bg(visualiser);
	drawlines(visualiser, heart->input);
	drawrooms(visualiser, heart->input);
	drawants(visualiser, ants);	
}
