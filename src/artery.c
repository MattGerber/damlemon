/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   artery.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 22:45:06 by bwebb             #+#    #+#             */
/*   Updated: 2020/04/30 10:56:28 by ben              ###   ########.fr       */
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

int		addarterynode(t_artery **artery, int id)
{
	t_artery *curnode;
	t_artery *newnode;

	curnode = *artery;
	while (curnode && curnode->next)
		curnode = curnode->next;
	if (!(newnode = malloc(sizeof(t_artery))))
		return (0);
	newnode->id = id;
	newnode->vein = NULL;
	newnode->ants = 0;
	newnode->next = NULL;
	if (*artery)
		curnode->next = newnode;
	else
		*artery = newnode;
	return (1);
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