/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   artery.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:43:03 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/17 18:11:11 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int		nodeaddartery(t_cluster **cluster, t_path *path, t_room *nextroom)
{
	t_artery    *nd;
	t_artery	*prevnode;

	nd = (*cluster)->artery;
	prevnode = NULL;
	while (nd)
	{
		prevnode = nd;
		nd = nd->next;
	}
	if (!(nd = (t_artery *)malloc(sizeof(t_artery))))
		return (0);
	nd->moves = 0;
    nd->path = path;
    nodeaddpath(&nd->path, nextroom);
	nd->next = NULL;
	if (prevnode)
		prevnode->next = nd;
	return ((validpath(nd->path)) ? 1 : -1);
}

t_room  *findstart(t_room *rooms)
{
    while (!rooms->bstart)
        rooms = rooms->next;
    return (rooms);
}

void	delarteryend(t_cluster **cluster)
{
	t_artery *artery;
	
	artery = (*cluster)->artery;
	while (artery->next->next)
		artery = artery->next;
	delpath(&(artery->next->path));
	free(artery->next);
	artery->next = NULL;
}

void    tunnel(t_cluster **cluster, t_path **path)
{
    int 	i;
	t_links	*temp;

	temp = (*cluster)->links;
	while (temp)
	{
	if (temp->from == (*path)->room)
	{
		if (nodeaddartery(cluster, (*path)->start, temp->to) == -1)
			delarteryend;
	}
	}
	
}

void    pump(t_cluster **cluster)
{
    (*cluster)->artery = (t_artery *)malloc(sizeof(t_artery));
    (*cluster)->artery->next = NULL;
    pathaddnode(&((*cluster)->artery->path), findstart((*cluster)->rooms));
    
     
}