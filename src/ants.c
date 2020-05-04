/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 22:49:16 by bwebb             #+#    #+#             */
/*   Updated: 2020/05/04 13:06:34 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	initants(t_heart *heart)
{
	t_artery	*artrunner;
	t_artery	*shortvein;

	while (heart->ants)
	{
		shortvein = heart->artery;
		artrunner = shortvein->next;
		while (artrunner)
		{
			if (artrunner->ants < shortvein->ants)
				shortvein = artrunner;
			artrunner = artrunner->next;
		}
		shortvein->ants++;
		heart->ants--;
	}
	artrunner = heart->artery;
	while (artrunner)
	{
		artrunner->ants -= veinlen(artrunner->vein);
		artrunner = artrunner->next;
	}
}

void	putants(t_heart *heart)
{
	t_traffic	*ant;
	t_traffic	*tmp;

	ant = heart->traffic;
	while (ant)
	{
		ant->veinnode = ant->veinnode->next;
		ft_putchar('L');
		ft_putnbr(ant->id);
		ft_putchar('-');
		ft_putstr(ant->veinnode->node->name);
		if (ant->next)
			ft_putstr(" ");
		if (ant->veinnode->node->end)
		{
			tmp = ant;
			// (tmp->parent) ? tmp->parent = tmp->next ? tmp->next->parent = tmp->parent;
			if (tmp->parent)
				tmp->parent = tmp->next;
			else
				heart->traffic = tmp->next;
			if (tmp->next)
				tmp->next->parent = tmp->parent;
			ant = tmp->next;
			free(tmp);
		}
		else
			ant = ant->next;
	}
	ft_putendl("");
}

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
	newnode->parent = (curnode) ? curnode : NULL;
	if (curnode)
		curnode->next = newnode;
	else
		*traffic = newnode;
	return (1);
}

void	qants(t_heart *heart)
{
	int		id;
	t_artery *artery;

	id = 1;
	heart->ants = 1;
	while (heart->ants)
	{
		artery = heart->artery;
		heart->ants = 0;
		while (artery)
		{
			if (artery->ants)
			{
				if (!addant(&heart->traffic, id++, artery->vein))
					erexit(heart, "out of memory");
				artery->ants--;
				heart->ants = 1;
			}
			artery = artery->next;
		}
		putants(heart);
	}
	while (heart->traffic)
		putants(heart);
}