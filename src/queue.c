/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbolton <rbolton@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:36:38 by bwebb             #+#    #+#             */
/*   Updated: 2020/06/01 15:04:59 by rbolton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

/*
** Adds a new t_queue node to the queue and sets it to point to the t_network node passed.
*/

void	pushq(t_queue **queue, t_queue *parent, t_network *node, t_heart *heart)
{
	t_queue *curnode;
	t_queue *newnode;

	curnode = *queue;
	while (curnode && curnode->next)
		curnode = curnode->next;
	if (!(newnode = malloc(sizeof(t_queue))))
		erexit(heart, 2);
	newnode->parent = parent ? parent : NULL;
	newnode->node = node;
	newnode->next = NULL;
	if (*queue)
		curnode->next = newnode;
	else
		*queue = newnode;
}

/*
** Custom free function to free the queue.
*/

void	freeq(t_queue *q)
{
	if (q)
	{
		if (q->next)
			freeq(q->next);
		if (q->node && ((q->node->visited != 2) || (q->node->end)))
			q->node->visited = 0;
		free(q);
	}
}