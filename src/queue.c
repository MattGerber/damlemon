/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:36:38 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/31 11:50:56 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int		pushq(t_queue **queue, t_queue *parent, t_network *node)
{
	t_queue *curnode;
	t_queue *newnode;

	curnode = *queue;
	while (curnode && curnode->next)
		curnode = curnode->next;
	if (!(newnode = (t_queue*)malloc(sizeof(t_queue))))
		return (0);
	newnode->parent = parent ? parent : NULL;
	newnode->node = node;
	newnode->next = NULL;
	if (*queue)
		curnode->next = newnode;
	else
		*queue = newnode;
	// *((*queue) ? queue : &(curnode->next)) = newnode;
	return (1);
}

// int		inveinids(t_veinids *veinids, int id)
// {
// 	while (veinids)
// 	{
// 		if (veinids->id == id)
// 			return (1);
// 		veinids = veinids->next;
// 	}
// 	return (0);
// }

void	freeq(t_queue **queue, t_veinids *veinids, t_vein **curvein)
{
	t_veinids	*temp;
	
	if (queue)
	{
		temp = veinids;
		while (temp && temp->next && (temp->id != (*queue)->node->id))
			temp = temp->next;
		if (temp->id == (*queue)->node->id)
			addveinnode(curvein, (*queue)->node);
		if ((*queue)->next)
			freeq(&((*queue)->next), veinids, curvein);
		free(*queue);
		*queue = NULL;
	}
}