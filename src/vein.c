/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vein.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 22:45:26 by bwebb             #+#    #+#             */
/*   Updated: 2020/05/02 16:39:56 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int		addveinnode(t_vein **vein, t_network *room)
{
	t_vein *newnode;

	if (!(newnode = malloc(sizeof(t_vein))))
		return (0);
	newnode->node = room;
	newnode->next = *vein;
	room->visited = 2;
	*vein = newnode;
	return (room->start != 1);
}