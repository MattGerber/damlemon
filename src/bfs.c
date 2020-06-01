/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbolton <rbolton@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:28:33 by bwebb             #+#    #+#             */
/*   Updated: 2020/06/01 14:40:52 by rbolton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

/*
** Handles edge case where start and end are directly linked.
** Stops BFS from infinitely adding the start-end link.
*/

void	cutedge(t_inputchecks *inchecks)
{
	int			count;
	int			cutedge;
	t_network	**links;

	count = -1;
	links = (*inchecks->start)->links;
	while(links[++count])
		if (links[count]->id == (*inchecks->end)->id)
			cutedge = count;
	if (count != cutedge)
		links[cutedge] = links[count];
	links[count] = NULL;
}

/*
** Adds a node in the vein/path which points to the relevant roomnode for the current path.
*/

int		addveinnode(t_vein **vein, t_network *room, t_heart *heart)
{
	t_vein *newnode;

	if (!(newnode = malloc(sizeof(t_vein))))
		erexit(heart, 2);
	newnode->node = room;
	newnode->next = *vein;
	room->visited = 2;
	*vein = newnode;
	return (room->start != 1);
}

/*
** Starting at start, adds rooms to the queue that are one link away.
** Then starts moving through the queue and adding to the back of the queue all next rooms
** that are only one link away. Does this until end is found. 
** Then runs through the queue in reverse looking for the parents that form this path to end
** and adds the rooms to a vein/path for a new artery node.
** This is done until no more paths to end exist.
*/

int		search(t_heart *heart, t_artery *artery)
{
	t_queue		*q;
	int			i;

	q = NULL;
	pushq(&q, NULL, heart->network, heart);
	while (1)
	{
		i = -1;
		while (q->node->links[++i])
			if (!(q->node->links[i]->visited))
				pushq(&q, q, q->node->links[i], heart);
		q->node->visited = 1;
		if ((q->next == NULL) || (q->node->end))
			break ;
		q = q->next;
	}
	i = (q->node->end) ? 1 : 0;
	while ((i && addveinnode(&(artery->vein), q->node, heart)) || (!q->node->start))
		q = q->parent;
	freeq(q);
	if (i && artery->vein->next->node->end)
		cutedge(heart->inputchecks);
	return (i);
}

/*
** Triggers the Breadth First Search algorithm.
*/

int		bfs(t_heart *heart)
{
	int	i;
	t_artery	*artery;

	i = 0;
	while (search(heart, artery = addarterynode(heart, ++i)))
		artery->veinlen = veinlen(artery->vein);
	popart(heart);
	return(*heart->artery ? 1 : 0);
}