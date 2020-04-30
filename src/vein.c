/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vein.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 22:45:26 by bwebb             #+#    #+#             */
/*   Updated: 2020/04/30 10:57:18 by ben              ###   ########.fr       */
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
	if (!(newnode = malloc(sizeof(t_vein))))
		return (0);
	newnode->node = room;
	newnode->next = NULL;
	if (*vein)
		curnode->next = newnode;
	else
		*vein = newnode;
	return (1);
}