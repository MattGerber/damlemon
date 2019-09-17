/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:27:39 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/17 18:08:29 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

void	delpath(t_path **path)
{
	if ((*path)->next)
		delpath(&((*path)->next));
	free(*path);
}

int    pathaddnode(t_path **path, t_room *room)
{
	t_path	*nd;
	t_path	*prevnode;

	nd = *path;
	prevnode = NULL;
	while (nd)
	{
		prevnode = nd;
		nd = nd->next;
	}
	if (!(nd = (t_path *)malloc(sizeof(t_path))))
		return (0);
	nd->room = room;
    nd->next = NULL;
	if (!path)
		path = nd;
	if (prevnode)
		prevnode->next = nd;
    return (1);
}