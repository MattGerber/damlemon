/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vein.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 22:45:26 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/22 16:54:00 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int		addveinnode(t_vein **vein, t_network *room)
{
	t_vein *curNode;
	t_vein *newNode;

	curNode = *vein;
	while (curNode && curNode->next)
		curNode = curNode->next;
	if (!(newNode = (t_vein*)malloc(sizeof(t_vein))))
		return (0);
	newNode->node = room;
	newNode->next = NULL;
	if (*vein)
		curNode->next = newNode;
	else
		*vein = newNode;
	// *((*vein) ? vein : &(curNode->next)) = newNode;
	return (1);
}