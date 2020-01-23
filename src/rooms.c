/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:18:59 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/23 14:31:25 by bwebb            ###   ########.fr       */
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
		while(temp && temp->next && (temp = temp->next))
			if (temp->roomnode && ft_strequ(temp->roomnode->name, links->line))
				break ;
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
	while (map)
	{
		if (islink(map->line, NULL))
		{
			arr = ft_strsplit(map->line, '-');
			if (ft_strequ(arr[0], node->name) || ft_strequ(arr[1], node->name))
			{
				i++;	
				addinputnode(&links, ft_strdup(arr[ft_strequ(arr[0], node->name)]));
			}
			while (arr[0])
    			free((arr++)[0]);
		}
		map = map->next;
	}
	node->links = poplinks(links, inputnodes, i);
	freeinputlist(&links);
}

void	initroomnodes(t_heart **heart)
{
	t_input	*input;
	char	**arr;
	
	(*heart)->ants = ft_atoi((*heart)->input->line);
	input = (*heart)->input->next;
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
			while (arr[0])
    			free((arr++)[0]);
			compilelinks(input->roomnode, input, (*heart)->input);
		}
		input = input->next;
	}
	(*(*heart)->inputchecks->start)->start = 1;
	(*(*heart)->inputchecks->end)->start = 0;
}

void	resetvisits(t_heart **heart)
{
	t_input	*input;
	
	input = (*heart)->input;
	while (input)
	{
		if (input->roomnode)
			input->roomnode->visited = 0;
		input = input->next;
	}
}