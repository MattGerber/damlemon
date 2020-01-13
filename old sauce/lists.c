/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:43:02 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/17 17:15:21 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int		nodeaddin(t_in **node, char *buff)
{
	t_in	*nd;
	t_in	*prevnode;

	nd = *node;
	prevnode = NULL;
	while (nd)
	{
		prevnode = nd;
		nd = nd->next;
	}
	if (!(nd = (t_in *)malloc(sizeof(t_in))))
		return (0);
	nd->line = buff;
	nd->next = NULL;
	if (!*node)
		*node = nd;
	if (prevnode)
		prevnode->next = nd;
	return (1);
}