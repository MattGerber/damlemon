/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vein.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 22:45:26 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/22 17:32:55 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int		addveinnode(t_vein **vein, t_network *room)
{
	t_vein *curnode;
	t_vein *newnode;

	curnode = *vein;
	while (curnode && curnode->next)
		curnode = curnode->next;
	if (!(newnode = (t_vein*)malloc(sizeof(t_vein))))
		return (0);
	newnode->node = room;
	newnode->next = NULL;
	if (*vein)
		curnode->next = newnode;
	else
		*vein = newnode;
	// *((*vein) ? vein : &(curnode->next)) = newnode;
	return (1);
}