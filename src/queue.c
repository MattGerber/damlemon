/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:36:38 by bwebb             #+#    #+#             */
/*   Updated: 2020/05/02 16:45:14 by ben              ###   ########.fr       */
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
	if (!(newnode = malloc(sizeof(t_queue))))
		return (0);
	newnode->parent = parent ? parent : NULL;
	newnode->node = node;
	newnode->next = NULL;
	if (*queue)
		curnode->next = newnode;
	else
		*queue = newnode;
	return (1);
}

void	freeq(t_queue *q)
{
	if (q->next)
		freeq(q->next);
	if ((q->node->visited != 2) || (q->node->end))
		q->node->visited = 0;
	free(q);
}