#include "../includes/visualiser.h"

t_ant	*v_initants(int ants)
{
	t_ant	*head;
	t_ant	*list;
	t_ant	*newnode;
	int		i;

	i = 1;	
	head = malloc(sizeof(t_ant));
	list = head;
	list->id = i;
	list->active = 0;
	while (i < ants)
	{
		newnode = malloc(sizeof(t_ant));
		list->next = newnode;
		list = list->next;
		i++;
		list->id = i;
		list->active = 0;
	}
	list->next = NULL;
	return(head);
}

t_ant	*setstart(t_ant *ant, t_input *input)
{
	t_ant		*temp;
	t_network	*rooms;

	while(input->next)
	{
		if (input->roomnode)
			if (input->roomnode->start)
				break ;
		input = input->next;
	}	
	temp = ant;
	rooms = input->roomnode;
	rooms->visited = 1;
	while(temp)
	{
		temp->room = rooms;
		temp->prev = NULL;
		temp = temp->next;
	}
	return (ant);
}

void	*execmove(t_ant	*ants, char *move, t_input *rooms)
{
	char	**second;
	t_ant	*anttmp;
	t_input *roomtmp;

		anttmp = ants;
		roomtmp = rooms;
			second = ft_strsplit(move, '-');

			while( anttmp && anttmp->id != v_atoi(second[0])){
				anttmp = anttmp->next;
			}
			while(roomtmp)
			{
				if (roomtmp->roomnode)
				{
					if(ft_strequ(roomtmp->roomnode->name, second[1]))
					{
						anttmp->prev = anttmp->room;
						anttmp->room = roomtmp->roomnode;
						break ;
					}
				}
				roomtmp = roomtmp->next;
			}
			freearr(second);
}

int		eventcheck(t_vis *visualiser, t_heart *heart, t_ant *ants, t_input *movelist)
{
	SDL_Event	event;
	char		**move;
	int			i;
	int			exec;

	i = 0;
	exec = 0;
	while (SDL_PollEvent(&event))
	{
		if ((event.type == SDL_KEYDOWN && KEY_Q) || event.type == SDL_QUIT)
				visualiser->close = 1;
		if (event.type == SDL_KEYDOWN && KEY_N  && movelist && !visualiser->active)
		{
			move = ft_strsplit(movelist->line, ' ');
			i = 0;
			while (move[i]){
				execmove(ants, move[i], heart->input);
				i++;
			}
			visualiser->active = 1;
			freearr(move);
			exec = 1;
		}
		if (event.type == SDL_KEYDOWN && KEY_R && !visualiser->active)
		{
			setstart(ants, heart->input);
		}
	}
	return (exec);
}