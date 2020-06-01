/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbolton <rbolton@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:18:59 by bwebb             #+#    #+#             */
/*   Updated: 2020/06/01 11:52:35 by rbolton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

t_network	**addlinks(t_input *links, t_input *inputlist, int linkcount, t_heart *heart)
{
	t_network	**linksarr;
	t_input		*temp;

	if (!(linksarr = malloc(sizeof(t_network*) * (linkcount + 1))))
		erexit(heart, 2);
	linkcount = 0;
	while (links)
	{
		temp = inputlist;
		while(temp && !(isroom(temp->line, heart) && ft_strequ(temp->roomnode->name, links->line)))
			temp = temp->next;
		linksarr[linkcount++] = temp->roomnode;
		links = links->next;
	}
	linksarr[linkcount] = NULL;
	return(linksarr);
}

void	compilelinks(t_network *roomnode, t_input *inputlistlinks, t_input *inputlist, t_heart *heart)
{
	t_input		*links;
	t_input		*tmp;
	char		*linkedroomname;
	char	**arr;
	int		i;

	i = 0;
	links = NULL;
	while (inputlistlinks)
	{
		if (islink(inputlistlinks->line, NULL, heart))
		{
			if (!(arr = ft_strsplit(inputlistlinks->line, '-')))
				erexit(heart, 2);
			if (ft_strequ(arr[0], roomnode->name) || ft_strequ(arr[1], roomnode->name))
			{
				tmp = links;
				linkedroomname = ft_strdup(arr[ft_strequ(arr[0], roomnode->name)]);

				while (tmp)
				{
					if (ft_strequ(roomnode->name, linkedroomname))
						break ;
					tmp = tmp->next;
				}

				if (!tmp)
				{
					if (!(addinputnode(&links, linkedroomname)))
					{
						freearr(arr);
						free(linkedroomname);
						freeinputlist(links);
						erexit(heart, 2);
					}
					i++;
				}
				else
					free(linkedroomname);
			}
			freearr(arr);
		}
		inputlistlinks = inputlistlinks->next;
	}
	roomnode->links = addlinks(links, inputlist, i, heart);
	freeinputlist(links);
}

void	notenoughlinks(t_heart *heart, t_input	*inputlistlinks)
{
	t_input	*inputlist;
	inputlist = heart->input;
	while(!islink(inputlist->line, NULL, heart))
	{

		if (inputlist->roomnode)
			compilelinks(inputlist->roomnode, inputlistlinks, heart->input, heart);
		inputlist = inputlist->next;
	}
}

void	initroomnodes(t_heart *heart)
{
	t_input	*input;
	char	**arr;
	int		id;

	heart->ants = ft_atoi(heart->input->line);
	input = heart->input->next;
	id = 1;
	while (!islink(input->line, NULL, heart))
	{
		if (isroom(input->line, heart))
		{
			if (!(input->roomnode = malloc(sizeof(t_network))))
				erexit(heart, 2);
			if (!(arr = ft_strsplit(input->line, ' ')))
				erexit(heart, 2);
			if (!(input->roomnode->name = ft_strdup(arr[0])))
			{
				freearr(arr);
				erexit(heart, 2);
			}
			input->roomnode->x = ft_atoi(arr[1]);
			input->roomnode->y = ft_atoi(arr[2]);
			input->roomnode->start = 0;
			input->roomnode->end = 0;
			input->roomnode->visited = 0;
			input->roomnode->id = id++;
			freearr(arr);
		}
		input = input->next;
	}
	notenoughlinks(heart, input);
	(*heart->inputchecks->start)->start = 1;
	(*heart->inputchecks->end)->end = 1;
}

void	freeroom(t_network *room)
{
	if (room)
	{
		if (room->name)
			free(room->name);
		if (room->links)
			free(room->links);
		free(room);
	}
}