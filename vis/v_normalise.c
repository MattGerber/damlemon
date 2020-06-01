#include "../includes/visualiser.h"

void	normalise_coords(t_heart *heart)
{	
	int		bigx = 0;
	int		bigy = 0;
	int		smallx = 0;
	int		smally = 0;
	int		r;
	t_input	*room;

	room = heart->input;
	while(!room->roomnode)
		room = room->next;
	bigx = room->roomnode->x;
	bigy = room->roomnode->y;
	smallx = room->roomnode->x;
	smally = room->roomnode->y;
	while(room->line[0] != 'L')
	{
		if (room->roomnode)
		{
			if(bigx < room->roomnode->x)
				bigx = room->roomnode->x;
			if(bigy < room->roomnode->y)
				bigy = room->roomnode->y;
			if(smallx > room->roomnode->x)
				smallx = room->roomnode->x;
			if(smally > room->roomnode->y)
				smally = room->roomnode->y;
		}
		room = room->next;
	}
	room = heart->input;
		while(room->line[0] != 'L')
	{
		if (room->roomnode)
		{
			room->roomnode->x = ((((double)room->roomnode->x - (double)smallx) / ((double)bigx - (double)smallx)) * (WIDTH - 300)) + 100;
			room->roomnode->y = ((((double)room->roomnode->y - (double)smally) / ((double)bigy - (double)smally)) * (HEIGHT- 300)) + 100;
		}
		room = room->next;
	}

}
