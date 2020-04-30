/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traffic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:35:46 by bwebb             #+#    #+#             */
/*   Updated: 2020/04/30 15:04:59 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int		addant(t_traffic **traffic, int	id, t_vein	*veinnode)
{
	t_traffic *curnode;
	t_traffic *newnode;

	curnode = *traffic;
	while (curnode && curnode->next)
		curnode = curnode->next;
	if (!(newnode = malloc(sizeof(t_traffic))))
		return (0);
	newnode->id = id;
	newnode->veinnode = veinnode;
	newnode->next = NULL;
	if (*traffic)
	{
		newnode->parent = curnode;
		curnode->next = newnode;
	}
	else
	{
		newnode->parent = NULL;
		*traffic = newnode;
	}
	// *((*inputList) ? inputList : &(curnode->next)) = newnode;
	return (1);
}