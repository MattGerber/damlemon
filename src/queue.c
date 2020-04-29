/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:36:38 by bwebb             #+#    #+#             */
/*   Updated: 2020/04/29 18:00:19 by ben              ###   ########.fr       */
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
	printf("the  memory address of newnode->parent is: %p\n", newnode->parent);
	newnode->parent = parent ? parent : NULL;//deleting inputchecks->end here on here
	newnode->node = node;
	newnode->next = NULL;
	if (*queue)
		curnode->next = newnode;
	else
		*queue = newnode;
	return (1);
}

void	freeq(t_queue **queue, t_veinids *veinids, t_vein **curvein)
{
	t_veinids	*temp;
	t_vein		*tmp;

	if (queue)
	{
		temp = veinids;
		while (temp && temp->next && (temp->id != (*queue)->node->id))
			temp = temp->next;
		(*queue)->node->visited = 0;
		if (temp && (temp->id == (*queue)->node->id))
		{
			tmp = *curvein;
			while (tmp && (tmp->node->id != (*queue)->node->id))
				tmp = tmp->next;
			if (!tmp)
				addveinnode(curvein, (*queue)->node);
			if (!((*queue)->node->start || (*queue)->node->end))
				(*queue)->node->visited = 1;
		}
		if ((*queue)->next)
			freeq(&((*queue)->next), veinids, curvein);
		free(*queue);
		*queue = NULL;
	}
}