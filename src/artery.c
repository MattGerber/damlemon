/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   artery.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 22:45:06 by bwebb             #+#    #+#             */
/*   Updated: 2020/05/06 15:27:17 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int		veinlen(t_vein *vein)
{
	int	i;

	i = 0;
	while (vein)
	{
		i++;
		vein = vein->next;
	}
	return (i);
}

t_artery	*addarterynode(t_heart *heart, int id)
{
	t_artery *curnode;
	t_artery *newnode;

	curnode = *heart->artery;
	while (curnode && curnode->next)
		curnode = curnode->next;
	if (!(newnode = malloc(sizeof(t_artery))))
		erexit(heart, 2);
	newnode->id = id;
	newnode->vein = NULL;
	newnode->veinlen = 0;
	newnode->ants = 0;
	newnode->next = NULL;
	if (curnode)
		curnode->next = newnode;
	else
		*heart->artery = newnode;
	return (newnode);
}

void	popart(t_artery *artery)
{
	t_artery	*prev;

	if (artery)
	{
		prev = NULL;
		while (artery->next)
		{
			prev = artery;
			artery = artery->next;
		};
		freevein(artery->vein);
		free(artery);
		if (prev)
			prev->next = NULL;
	}
}