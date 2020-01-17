/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traffic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:35:46 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/17 13:56:12 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int		addant(t_traffic **traffic, int	id, t_vein	*veinnode)
{
	t_traffic *curNode;
	t_traffic *newNode;

	curNode = *traffic;
	while (curNode && curNode->next)
		curNode = curNode->next;
	if (!(newNode = (t_traffic*)malloc(sizeof(t_traffic))))
		return (0);
	newNode->id = id;
	newNode->veinnode = veinnode;
	newNode->next = NULL;
	if (*traffic)
	{
		newNode->parent = curNode;
		curNode->next = newNode;
	}
	else
	{
		newNode->parent = NULL;	
		*traffic = newNode;
	}
	// *((*inputList) ? inputList : &(curNode->next)) = newNode;
	return (1);
}