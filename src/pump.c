/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 22:49:16 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/31 13:22:47 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	initants(t_heart **heart)
{
	t_artery	*artrunner;
	t_artery	*shortvein;
	
	// artrunner = (*heart)->artery;
	// while (artrunner)
	// {
	// 	artrunner->ants = veinlen(artrunner->vein);
	// 	artrunner = artrunner->next;
	// }
	while ((*heart)->ants)
	{
		shortvein = (*heart)->artery;
		artrunner = shortvein->next;
		while (artrunner)
		{
			if (artrunner->ants < shortvein->ants)
				shortvein = artrunner;
			artrunner = artrunner->next;
		}
		shortvein->ants++;
		(*heart)->ants--;
	}
	artrunner = (*heart)->artery;
	while (artrunner)
	{
		artrunner->ants -= veinlen(artrunner->vein);
		artrunner = artrunner->next;
	}	
}

//write removeparkedants
void	removeparkedants(t_heart **heart)
{
	t_traffic	*valve;
	t_traffic	*temp;

	valve = (*heart)->traffic;
	temp = NULL;
	while (valve)
	{
		if (valve->veinnode->node->end)
		{
			if (!temp)
			{
				temp = valve;
				valve = valve->next;
				(*heart)->traffic = valve;
				free(temp);
				temp = NULL;
			}
			else
			{
				temp->next = valve->next;
				free(valve);
				valve = temp->next;
			}
		}
		else
			valve = valve->next;
	}
}

void	beat(t_heart **heart)
{
	t_artery	*blood;
	t_traffic	*valve;
	int	i;
	
	initants(heart);
	blood = (*heart)->artery;
	i = 1;
	while (1)
	{
		blood = (*heart)->artery;
		while (blood)
		{
			if (blood->ants)
			{	
				addant(&(*heart)->traffic, i++, blood->vein);
				blood->ants--;
			}
			blood = blood->next;
		}
		removeparkedants(heart);
		valve = (*heart)->traffic;
		while (valve)
		{
			valve->veinnode = valve->veinnode->next;
			ft_putchar('L');
			ft_putnbr(valve->id);
			ft_putchar('-');
			ft_putstr(valve->veinnode->node->name);
			if (valve->next)
				ft_putstr(" ");
			valve = valve->next;
		}
		if (!(*heart)->traffic)
			break ;
		ft_putendl("");
	}
}