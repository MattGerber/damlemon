/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:43:02 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/16 17:46:43 by bwebb            ###   ########.fr       */
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
	(*room)->links = NULL;
	(*room)->next = NULL;
	i = 1;
	while (i < 3)
		free(line[i++]);
	free(line);
}

void	initroomlist(t_in **inlist, t_room **roomlist)
{
	t_in	*temp;

	temp = (*inlist)->next;
	while (!(ft_strchr(temp->line, '-')))
	{
		if ((ft_strchr(temp->line, '#')))
		{
			if (ft_strequ(temp->line, "##start") || ft_strequ(temp->line, "##end"))
			{
				nodeaddroom(roomlist, ft_strsplit(temp->next->line, ' '), (ft_strequ(temp->line, "##start")) ? ft_atoi((*inlist)->line) : 0, (ft_strequ(temp->line, "##end")) ? 1 : 0);
				temp = temp->next;
			}
			temp = temp->next;
		}
		else if (!(ft_strchr(temp->line, '-')))
		{
			nodeaddroom(roomlist, ft_strsplit(temp->next->line, ' '), 0, 0);
		temp = temp->next;
		}
	}
}

int		nodeaddin(t_in **node, char *buff)
{
	t_in	*nd;
	t_in	*prevnode;

	nd = *node;
	prevnode = NULL;
	while (nd)
	{
		prevnode = nd;
		nd = nd->next;
	}
	if (!(nd = (t_in *)malloc(sizeof(t_in))))
		return (0);
	nd->line = buff;
	nd->next = NULL;
	if (!*node)
		*node = nd;
	if (prevnode)
		prevnode->next = nd;
	return (1);
}