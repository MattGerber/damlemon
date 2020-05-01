/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:18:59 by bwebb             #+#    #+#             */
/*   Updated: 2020/05/01 15:50:45 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

t_network	**poplinks(t_input *links, t_input *inputlist, int linkcount)
{
	t_network	**linksarr;
	t_input		*temp;

	linksarr = malloc(sizeof(t_network*) * (linkcount + 1));
	linkcount = 0;
	while (links)
	{
		temp = inputlist;
		while(temp && !(isroom(temp->line) && ft_strequ(temp->roomnode->name, links->line)))
			temp = temp->next;
		linksarr[linkcount++] = temp->roomnode;
		links = links->next;
	}
	linksarr[linkcount] = NULL;
	return(linksarr);
}

void	compilelinks(t_network *roomnode, t_input *inputlistlinks, t_input *inputlist)
{
	t_input		*links;
	char	**arr;
	int		i;

	i = 0;
	links = NULL;
	while (inputlistlinks)
	{
		if (islink(inputlistlinks->line, NULL))
		{
			arr = ft_strsplit(inputlistlinks->line, '-');
			if (ft_strequ(arr[0], roomnode->name) || ft_strequ(arr[1], roomnode->name))
			{
				addinputnode(&links, ft_strdup(arr[ft_strequ(arr[0], roomnode->name)]));
				i++;
			}
			while (arr[0])
    			free((arr++)[0]);
		}
		inputlistlinks = inputlistlinks->next;
	}
	roomnode->links = poplinks(links, inputlist, i);
	freeinputlist(links);
}

void	notenoughlinks(t_heart *heart, t_input	*inputlistlinks)
{
	t_input	*inputlist;

	inputlist = heart->input;
	while(!islink(inputlist->line, NULL))
	{
		if (inputlist->roomnode)
			compilelinks(inputlist->roomnode, inputlistlinks, heart->input);
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
	while (!islink(input->line, NULL))
	{
		if (isroom(input->line))
		{
			input->roomnode = malloc(sizeof(t_network));
			arr = ft_strsplit(input->line, ' ');
			input->roomnode->name = ft_strdup(arr[0]);
			input->roomnode->x = ft_atoi(arr[1]);
			input->roomnode->y = ft_atoi(arr[2]);
			input->roomnode->start = 0;
			input->roomnode->end = 0;
			input->roomnode->visited = 0;
			input->roomnode->id = id++;
			while (arr[0])
    			free((arr++)[0]);
		}
		input = input->next;
	}
	notenoughlinks(heart, input);
	(*heart->inputchecks->start)->start = 1;
	(*heart->inputchecks->end)->end = 1;
}