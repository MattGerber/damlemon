/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:18:59 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/22 17:42:09 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	poplinks(t_network **node, t_input *links)
{
	t_input	*linked;
	int		i;
	char	**arr;
	
	i = 0;
	while (links)
	{
		if (islink(links, NULL))
		{
			arr = ft_strsplit(links->line, ' ');
			if (ft_strequ(arr[0], (*node)->name))
			{
				addinputnode(&linked, ft_strdup(arr[1]));
				i++;
			}
			if (ft_strequ(arr[1], (*node)->name))
			{
				addinputnode(&linked, ft_strdup(arr[0]));
				i++;
			}
			while (arr[0])
    			free((arr++)[0]);
		}
		links = links->next;
	}
	arr = (char **)malloc(sizeof(char *) * i);
	links = linked;
	while (arr[0])
	{
		arr[0] = ft_strdup(links->line);
		arr++;
		links = links->next;
	}
	freeinputlist(&linked);
	(*node)->links = arr;
}

void	setstartend(t_heart **heart)
{
	t_input *input;

	input = (*heart)->input;
	while (!islink(input->line, NULL))
	{
		if (ft_strequ(input->line, "##start") == 1)
		{
			input->next->roomnode->start = 1;
			(*heart)->network = input->next->roomnode;	
		};
		if (ft_strequ(input->line, "##end") == 1)
			input->next->roomnode->end = 1;
		input = input->next;
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
			input->roomnode->name = arr[0];
			input->roomnode->x = ft_atoi(arr[1]);
			input->roomnode->y = ft_atoi(arr[2]);
			input->roomnode->start = 0;
			input->roomnode->end = 0;
			input->roomnode->visited = 0;
			while (arr[0])
    			free((arr++)[0]);
			poplinks(&(input->roomnode), input);
		}
		input = input->next;
	}
	setstartend(heart);
}

void	resetvisits(t_heart **heart)
{
	t_input	*input;
	
	input = (*heart)->input;
	while (input)
	{
		input->roomnode->visited = 0;
		input = input->next;
	}
}