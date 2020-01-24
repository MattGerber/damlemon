/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:18:59 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/24 14:29:48 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

t_network	**poplinks(t_input *links, t_input *input, int linkcount)
{
	t_network	**linksarr;
	t_input		*temp;
	int			i;

	// ft_putendl("");
	// ft_putendl("{poplinks {links}}");
	// putinputlist(links);
	linksarr = (t_network**)malloc(sizeof(t_network*) * (linkcount + 1));
	// ft_putendl("");
	// ft_putendl("linkcount : ");
	// ft_putnbr(linkcount);
	// ft_putendl("");
	// ft_putendl("");
	// ft_putendl("{input list}");
	// putinputlist(input);
	// ft_putendl("");
	
	i = 0;
	while (links)
	{
		temp = input;
		
	// 	ft_putendl("");
	// ft_putendl("{temp input list}");
	// putinputlist(temp);
	// ft_putendl("");
	// ft_putendl("links line");
	// ft_putendl(links->line);
	// ft_putendl("");
	putinputlist(temp);
		while(temp)
		{

			ft_putendl("");
			ft_putendl("{temp line}");
			ft_putendl(temp->line);
			ft_putendl("{temp roomnode name}");
			
			ft_putendl((temp->roomnode) ? temp->roomnode->name : "{no roomnode}");
			ft_putendl("");
			if (isroom(temp->line) && ft_strequ(temp->roomnode->name, links->line))
				break ;
			temp = temp->next;
		}
		ft_putendl("HERHEHRHHR");
		ft_putendl(temp->roomnode->name);
		linksarr[i] = temp->roomnode;
		ft_putendl("HERE2");
		i++;
		links = links->next;
	}
	linksarr[i] = NULL;
	// i = 0;
	// ft_putendl("");
	// ft_putendl("{linksarr}");
	// while (linksarr[i])
	// {
	// 	ft_putstr("index [");
	// 	ft_putnbr(i++);
	// 	ft_putstr("] = ");
	// 	ft_putendl(linksarr[i]->name);
	// };
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
	// ft_putendl("");
	// ft_putstr("node name {");
	// ft_putstr(node->name);
	// ft_putendl("} links");
	// putinputlist(links);
	// ft_putendl("");
	node->links = poplinks(links, inputnodes, i);
	freeinputlist(&links);
}

void	notenoughlinks(t_heart **heart)
{
	t_input	*temp;

	temp = (*heart)->input;
	while(!islink(temp->line, NULL))
	{
	ft_putendl("HERE!");
		if (temp->roomnode)
			compilelinks(temp->roomnode, temp, (*heart)->input);
		temp = temp->next;
	}
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
		}
		input = input->next;
	}
	notenoughlinks(heart);
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