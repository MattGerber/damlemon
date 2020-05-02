/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 22:49:16 by bwebb             #+#    #+#             */
/*   Updated: 2020/05/02 18:33:02 by ben              ###   ########.fr       */
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

void	beat(t_heart *heart, t_artery *blood, int id)
{
	blood = heart->artery;
	while (blood)
	{
		if (blood->ants)
		{
			addant(&heart->traffic, id++, blood->vein);
			blood->ants--;
		}
		blood = blood->next;
	}
	putants(heart);
	if (heart->traffic)
		beat(heart, heart->artery, id);
}