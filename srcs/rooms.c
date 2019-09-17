/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:36:45 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/17 16:07:44 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

t_room	**nodeaddroom(t_room **node, char **line, int bstart, int bend)
{
	t_room	*nd;
	t_room	*prevnode;

	nd = *node;
	prevnode = NULL;
	while (nd)
	{
		prevnode = nd;
		nd = nd->next;
	}
	if (!(nd = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	initroom(&nd, line, bstart, bend);
	if (!*node)
		*node = nd;
	if (prevnode)
		prevnode->next = nd;
	return (node);
}

void	initroom(t_room **room, char **line, int bstart, int bend)
{
	int	i;

	(*room)->rname = line[0];//might memory leak when its finished.need to free w/list
	(*room)->xcord = ft_atoi(line[1]);
	(*room)->ycord = ft_atoi(line[2]);
	(*room)->bant = bstart;
	(*room)->bstart = bstart ? 1 : 0;
	(*room)->bend = bend;
	(*room)->next = NULL;
	i = 1;
	while (i < 3)
		free(line[i++]);
	free(line);
}

void	initroomlist(t_cluster **cluster)
{
	t_in	*temp;

	temp = (*cluster)->input->next;
	while (!(ft_strchr(temp->line, '-')))
	{
		if ((ft_strchr(temp->line, '#')))
		{
			if (ft_strequ(temp->line, "##start") || ft_strequ(temp->line, "##end"))
			{
				nodeaddroom(&((*cluster)->rooms), ft_strsplit(temp->next->line, ' '), (ft_strequ(temp->line, "##start")) ? ft_atoi((*cluster)->input->line) : 0, (ft_strequ(temp->line, "##end")) ? 1 : 0);
				temp = temp->next;
			}
			temp = temp->next;
		}
		else if (!(ft_strchr(temp->line, '-')))
		{
			nodeaddroom(&((*cluster)->rooms), ft_strsplit(temp->next->line, ' '), 0, 0);
		temp = temp->next;
		}
	}
}

t_room  *findroom(t_room *roomlist, char *name)
{
    while (roomlist && !(ft_strequ(roomlist->rname, name)))
        roomlist = roomlist->next;
    return (roomlist);
}