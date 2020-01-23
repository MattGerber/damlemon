/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:01:47 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/23 15:07:20 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemon.h"

int		addcleannode(t_input **inputList, t_network *node)
{
	t_input *curnode;
	t_input *newnode;

	curnode = *inputList;
	while (curnode && curnode->next)
		curnode = curnode->next;
	if (!(newnode = (t_input*)malloc(sizeof(t_input))))
		return (0);
	newnode->roomnode = node;
	newnode->next = NULL;
	if (*inputList)
		curnode->next = newnode;
	else
		*inputList = newnode;
	return (1);
}

void	cleaninput(t_heart **heart)
{
	t_input	*temp;
	t_input *clean;

	temp = (*heart)->input;
	while (temp)
	{
		if (temp->roomnode)
			addcleannode(&clean, temp->roomnode);
		temp = temp->next;
	}
	freeinputlist(&(*heart)->input);
	(*heart)->input = clean;
}