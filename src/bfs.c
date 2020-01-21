/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:28:33 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/21 18:17:03 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	initvisited(t_heart **heart)
{
	
};

int		inveinid(t_veinids *veinids, int id)
{
	while (veinids)
	{
		if (veinids->id == id)
			return (1);
		veinids = veinids->next;
	}
	return (0);
}

//write addveinids

//write control func for arteries

int		bfs(t_heart **heart)//fix to find 1 path at a time
{
	t_queue		*q;
	t_veinids	*veinids;
	int			i;

	pushq(&q, NULL, &(*heart)->network);
	while (q)
	{
		i = 0;
		while (q->node->links[i])
			if (!(q->node->links[i]->visited))
				pushq(&q, &q, &(q->node->links[i++]));
		if (!q->next || q->node->end)
			break ;
		q = q->next;
	}
	if (!q->node->end)
		return (0);
	while (q->parent)//fix everthing after this shit cause its just the concept
	{
		addveinids(q->node->id, veinids);
		q = q->parent;
	}
	freeq(q, addveinids);
	return (1);
}