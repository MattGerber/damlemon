/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:36:38 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/21 16:57:51 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int		pushq(t_queue **queue, t_queue **parent, t_network **node)
{
	t_queue *curNode;
	t_queue *newNode;

	curNode = *queue;
	while (curNode && curNode->next)
		curNode = curNode->next;
	if (!(newNode = (t_queue*)malloc(sizeof(t_queue))))
		return (0);
	newNode->parent = (*parent) ? *parent : NULL;
	newNode->node = *node;
	newNode->next = NULL;
	if (*queue)
		curNode->next = newNode;
	else
		*queue = newNode;
	// *((*queue) ? queue : &(curNode->next)) = newNode;
	return (1);
}

void	freeq(t_queue *queue, t_veinids *veinids, t_vein **curvein)
{
	t_veinids	*temp;
	
	if (queue)
	{
		temp = veinids;
		while (temp && temp->next && (temp->id != queue->node->id))
			temp = temp->id;
		if (temp->id == queue->node->id)
			addveinnode(curvein, queue->node);
		if (queue->next)
			freeq(queue->next, veinids, curvein);
		free(queue);
	}
}