/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   artery.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 22:45:06 by bwebb             #+#    #+#             */
/*   Updated: 2020/05/11 11:32:55 by ben              ###   ########.fr       */
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

void	popart(t_heart *heart)
{
	t_artery	*prev;
	t_artery	*cur;

	cur = *heart->artery;
	if (cur)
	{
		prev = NULL;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		};
		freevein(cur->vein);
		free(cur);
		if (prev)
			prev->next = NULL;
		else
		{
			*heart->artery = NULL;
			heart->artery = NULL;
		}
	}
}

int		arterylength(t_artery *artery)
{
	int	i;

	i = 0;
	while(artery)
	{
		i++;
		artery = artery->next;
	}
	return (i);
}