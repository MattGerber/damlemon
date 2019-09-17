/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:15:11 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/17 16:07:01 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int    linksaddnode(t_cluster **cluster, t_room *from, t_room *to)
{
	t_links	*nd;
	t_links	*prevnode;

	nd = (*cluster)->links;
	prevnode = NULL;
	while (nd)
	{
		prevnode = nd;
		nd = nd->next;
	}
	if (!(nd = (t_links *)malloc(sizeof(t_links))))
		return (0);
	nd->from = from;
    nd->to = to;
    nd->next = NULL;
	if (!(*cluster)->links)
		(*cluster)->links = nd;
	if (prevnode)
		prevnode->next = nd;
    return (1);
}

void    initlinkslist(t_cluster **cluster)
{
    t_in    *tin;
    char    **split;

    tin = (*cluster)->input;
    while (!ft_strchr(tin->line, '-'))
        tin = tin->next;
    while (tin)
    {
        if (isins(tin))
        {
            split = ft_strsplit(tin->line, '-');
            linksaddnode(cluster, findroom((*cluster)->rooms, split[0]), findroom((*cluster)->rooms, split[1]));
            free(split[0]);
            free(split[1]);
        }
        tin = tin->next;
    }
}