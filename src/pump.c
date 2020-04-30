/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 22:49:16 by bwebb             #+#    #+#             */
/*   Updated: 2020/04/30 17:01:35 by ben              ###   ########.fr       */
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
	t_traffic	*valve;
	t_traffic	*tmp;

	valve = heart->traffic;
	while (valve)
	{
		valve->veinnode = valve->veinnode->next;
		ft_putchar('L');
		ft_putnbr(valve->id);
		ft_putchar('-');
		ft_putstr(valve->veinnode->node->name);
		if (valve->next)
			ft_putstr(" ");
		if (valve->veinnode->node->end)
		{
			tmp = valve;
			if (tmp->parent)
				tmp->parent = tmp->next;
			else
				heart->traffic = tmp->next;
			if (tmp->next)
				tmp->next->parent = tmp->parent;
			valve = tmp->next;
			free(tmp);
		}
		else
			valve = valve->next;
	}
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
	ft_putendl("");
	if (heart->traffic)
		beat(heart, heart->artery, id);
}