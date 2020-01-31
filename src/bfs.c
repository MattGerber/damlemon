/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:28:33 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/31 14:36:18 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	initvisited(t_heart *heart)
{
	t_input	*input;
	t_vein	*vein;
	t_artery	*artery;

	artery = heart->artery;
	resetvisits(heart);
	while (artery)
	{
		vein = artery->vein;
		while (!(vein->node->end))
		{
			input = heart->input;
			while (input && (input->roomnode->id != vein->node->id))
				input = input->next;
			if (input && (input->roomnode->id == vein->node->id))
				input->roomnode->visited = 1;
			vein = vein->next;
		}
		artery = artery->next;
	}
};



//write addveinids
void	addveinids(int id, t_veinids **veinids)
{
	t_veinids *curnode;
	t_veinids *newnode;

	curnode = *veinids;
	while (curnode && curnode->next)
		curnode = curnode->next;
	newnode = (t_veinids*)malloc(sizeof(t_veinids));
	newnode->id = id;
	newnode->next = NULL;
	if (*veinids)
		curnode->next = newnode;
	else
		*veinids = newnode;
	// *((*veinids) ? veinids : &(curnode->next)) = newnode;
}

void	freeveinids(t_veinids **veinids)
{
	if ((*veinids)->next)
		freeveinids(&(*veinids)->next);
	free(*veinids);
}

int		search(t_heart *heart, t_artery *artery)//fix to find 1 path at a time
{
	t_queue		*q;
	t_veinids	*veinids;
	int			i;

	q = NULL;
	pushq(&q, NULL, heart->network);
	while (q && !(q->node->end))
	{
		i = -1;
		while (q->node->links[++i])
			if (!(q->node->links[i]->visited))
				pushq(&q, q, q->node->links[i]);
		if (!(q->node->end))
			q->node->visited = 1;
		if (!q->next || q->node->end)
			break ;
		q = q->next;
	}
	if (!q->node->end)
	{
		//is gon leak here need to free the q
		return (0);
	}
	veinids = NULL;
	while (q->parent)
	{
		addveinids(q->node->id, &veinids);
		q = q->parent;
	}
	addveinids(q->node->id, &veinids);
	freeq(&q, veinids, &(artery->vein));
	freeveinids(&veinids);
	return (1);
}

int		bfs(t_heart *heart)
{
	int	i;
	t_artery	*artery;
	
	i = 0;
	while (1)
	{
		initvisited(heart);
		addarterynode(&heart->artery, ++i);
		artery = heart->artery;
		while (artery->next)
			artery = artery->next;
		if (!search(heart, artery))
			break ;
		artery->ants = veinlen(artery->vein);
	}
	popart(heart->artery);
	return(heart->artery ? 1 : 0);
}