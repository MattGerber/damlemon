/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   artery.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 22:45:06 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/22 16:40:29 by bwebb            ###   ########.fr       */
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

t_artery		**addarteryNode(t_artery **artery, int id)
{
	t_artery *curNode;
	t_artery *newNode;

	curNode = *artery;
	while (curNode && curNode->next)
		curNode = curNode->next;
	if (!(newNode = (t_artery*)malloc(sizeof(t_artery))))
		return (0);
	newNode->id = id;
	newNode->vein = NULL;
	newNode->ants = 0;
	newNode->next = NULL;
	if (*artery)
		curNode->next = newNode;
	else
		*artery = newNode;
	// *((*artery) ? artery : &(curNode->next)) = newNode;
	return (&newNode);
}

void	popart(t_artery *artery)
{
	t_artery	*prev;
	
	prev = NULL;
	while (artery && artery->next)
	{
		prev = artery;
		artery = artery->next;
	};
	if (artery)
		free(artery);
	if (prev)
		prev->next = NULL;
}