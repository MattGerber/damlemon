/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:18:59 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/31 15:52:56 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

t_network	**poplinks(t_input *links, t_input *input, int linkcount)
{
	t_network	**linksarr;
	t_input		*temp;
	int			i;

	linksarr = (t_network**)malloc(sizeof(t_network*) * (linkcount + 1));
	i = 0;
	while (links)
	{
		temp = input;
		while(temp)
		{
			if (isroom(temp->line) && ft_strequ(temp->roomnode->name, links->line))
				break ;
			temp = temp->next;
		}
		linksarr[i] = temp->roomnode;
		i++;
		links = links->next;
	}
	linksarr[i] = NULL;
	return(linksarr);
}

void	compilelinks(t_network *node, t_input *map, t_input *inputnodes)
{
	t_input		*links;
	char	**arr;
	int		i;
	
	i = 0;
	links = NULL;
	while (map)
	{
		if (islink(map->line, NULL))
		{
			arr = ft_strsplit(map->line, '-');
			if (ft_strequ(arr[0], node->name) || ft_strequ(arr[1], node->name))
			{
				addinputnode(&links, ft_strdup(arr[ft_strequ(arr[0], node->name)]));
				i++;
			}
			while (arr[0])
    			free((arr++)[0]);
		}
		map = map->next;
	}
	node->links = poplinks(links, inputnodes, i);
	freeinputlist(&links);
}

void	notenoughlinks(t_heart **heart)
{
	t_input	*temp;

	temp = (*heart)->input;
	while(!islink(temp->line, NULL))
	{
		if (temp->roomnode)
			compilelinks(temp->roomnode, temp, (*heart)->input);
		temp = temp->next;
	}
}

void	initroomnodes(t_heart **heart)
{
	t_input	*input;
	char	**arr;
	int		id;
	
	(*heart)->ants = ft_atoi((*heart)->input->line);
	input = (*heart)->input->next;
	id = 1;
	while (!islink(input->line, NULL))
	{
		if (isroom(input->line))
		{
			input->roomnode = (t_network*)malloc(sizeof(t_network));
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
	notenoughlinks(heart);
	(*(*heart)->inputchecks->start)->start = 1;
	(*(*heart)->inputchecks->end)->end = 1;
}