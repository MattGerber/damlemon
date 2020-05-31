#include "../includes/visualiser.h"

int		check_coords(t_heart *heart)
{
	t_input	*room1;
	t_input *room2;
	int change = 0;

	room1 = heart->input;
	while(room1->line[0] != 'L')
	{
		if (room1->roomnode)
		{
			room2 = heart->input->next;
			while (room2->line[0] != 'L')
			{
				if (room2->roomnode && room1 != room2)
				{
					if (room1->roomnode->x > room2->roomnode->x)
					{
						if (room1->roomnode->x - room2->roomnode->x < 20)
						{
							room2->roomnode->x++;
							room2->roomnode->x += 50;
							change = 1;
						}
					}
					else if (room2->roomnode->x - room1->roomnode->x < 20)
					{
						room1->roomnode->x++;
						room1->roomnode->x += 50;
						change = 1;
					}
					if (room1->roomnode->y > room2->roomnode->y)
					{
						if (room1->roomnode->y - room2->roomnode->y < 20)
						{
							room2->roomnode->y++;
							room2->roomnode->y += 50;
							change = 1;
						}
					}
					else if (room2->roomnode->y - room1->roomnode->y < 20)
					{
						room1->roomnode->y++;
						room1->roomnode->y += 50;
						change = 1;
					}
						
				}
				room2 = room2->next;
			}
		}
		room1 = room1->next;
	}
	return (change);
}

void	normalise_coords(t_input *room1)
{
	room1->roomnode->x += 100;
	room1->roomnode->y += 100;

}