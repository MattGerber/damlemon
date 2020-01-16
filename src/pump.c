/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 22:49:16 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/16 23:29:06 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int		arterylen(t_artery *artery)
{
	int	i;

	i = 0;
	while (artery)
	{
		i++;
		artery = artery->next;
	};
	return (i);
}

void	initveinlen(int **veins, t_artery *artery)
{
	int i;

	i = 0;
	while (artery)
	{
		(*veins)[i] = artery->veinlen;
		artery = artery->next;
		i++;
	};
	(*veins)[i] = NULL;
}

void	stackants(int ants, int **veins,  t_artery *artery)
{
	int	i;
	int	k;

	while (ants)
	{
		i = 0;
		k = 0;
		while ((*veins)[++i])
			if ((*veins)[i] < (*veins)[k])
				k = i;
		(*veins)[k]++;
		ants--;
	}
	i = 0;
	while (artery)
	{
		(*veins)[i] -= artery->veinlen;
		artery = artery->next;
		i++;
	};
}

void	beat(t_heart **heart)
{
	int		*veins;
	
	veins = (int*)malloc(sizeof(int) * arterylen((*heart)->artery));
	initveinlen(&veins, (*heart)->artery);
	stackants((*heart)->ants, &veins, (*heart)->artery);
	
	
	
}